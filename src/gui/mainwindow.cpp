#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mips_highlighter.h"
#include "tokenizer.h"
#include <QFileDialog>
#include "../assembler/mips_assembler.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_src_file(NULL)
{
    ui->setupUi(this);
    setup_text_editor();
    setup_error_table();

    connect(ui->tableWidget, SIGNAL(itemClicked(QTableWidgetItem*)), this, SLOT(tableItemClicked(int,int)));

   // setup_actions();
    //ui->menubar->addAction(m_newAct);
}

MainWindow::~MainWindow()
{
    if(m_src_file != NULL){
        delete m_src_file;
    }
    delete ui;
}

void MainWindow::setup_text_editor(){
    QFont font;
    font.setFamily("Courier");
    font.setStyleHint(QFont::Monospace);
    font.setFixedPitch(true);
    font.setPointSize(10);

    ui->textEdit->setFont(font);
    QFontMetrics metrics(font);
    ui->textEdit->setTabStopWidth(6 * metrics.width(' '));

    QBrush *brush = new QBrush();
    brush->setStyle(Qt::SolidPattern);
    brush->setColor(QColor(238, 238, 238));

    QTextEdit::ExtraSelection highlight;
    highlight.cursor = ui->textEdit->textCursor();
    highlight.format.setProperty(QTextFormat::FullWidthSelection, true);
    highlight.format.setBackground( *brush );

    QList<QTextEdit::ExtraSelection> extras;
    extras << highlight;
    ui->textEdit->setExtraSelections( extras );

    new mips_highlighter(ui->textEdit->document());
}

void MainWindow::setup_error_table(){
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->verticalHeader()->setVisible(false);

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    QTableWidgetItem* col_num = new QTableWidgetItem(QString("Err #"),QTableWidgetItem::Type);
    QTableWidgetItem* col_line = new QTableWidgetItem(QString("Line"),QTableWidgetItem::Type);
    QTableWidgetItem* col_col = new QTableWidgetItem(QString("Column"),QTableWidgetItem::Type);
    QTableWidgetItem* col_err = new QTableWidgetItem(QString("Error"),QTableWidgetItem::Type);

    ui->tableWidget->setHorizontalHeaderItem(0,col_num);
    ui->tableWidget->setHorizontalHeaderItem(1, col_line);
    ui->tableWidget->setHorizontalHeaderItem(2, col_col);
    ui->tableWidget->setHorizontalHeaderItem(3, col_err);
    //ui->tableWidget->setItem(0, 0, col_pCtx);
}

void MainWindow::update_title(){
    if(m_src_file == NULL){
        return;
    }
    QString title;
    title += QString::fromStdString(m_src_file->m_filename);
    if(m_is_changed){
        title += QString(" *");
    }
    title += QString(" - EzMIPS");
    this->setWindowTitle(title);
}

void MainWindow::save_with_dialog(){
    QString filename = QFileDialog::getSaveFileName(this, QString("Save file..."),
                                                    QString(""), QString("MIPS assembly file (*.s *.asm)"));
    m_src_file = new source_file(filename.toStdString());
}

void MainWindow::newFile(){

}

void MainWindow::on_actionNew_triggered()
{
    if(m_src_file != NULL){
        delete m_src_file;
    }

    m_src_file = new source_file("mips1.asm");
    m_is_changed = true;
    update_title();
}

void MainWindow::on_actionSave_triggered()
{
    if(m_src_file == NULL){
        save_with_dialog();
    }
    std::string dat = ui->textEdit->toPlainText().toStdString();
    m_src_file->set_data(dat.length(), (char*)dat.c_str());
    m_src_file->save();
    m_is_changed = false;
    update_title();
}

void MainWindow::on_actionAssemble_triggered()
{

}

void MainWindow::on_actionRun_triggered()
{
    // TODO:
    // clear all rows
    ui->tableWidget->setRowCount(0);

    if(m_src_file == NULL){
        save_with_dialog();
    }

    string dat = ui->textEdit->toPlainText().toStdString();
    m_src_file->set_data(dat.length(), (char*)dat.c_str());
    m_src_file->save();

    m_is_changed = false;
    update_title();

    mips_assembler a(m_src_file);
    runtime_context c;
    parser_context *pCtx = a.assemble(c);


    m_tbl_len_map.clear();

    for(vector<parser_error*>::iterator it = pCtx->get_parser_errors()->begin();
        it != pCtx->get_parser_errors()->end();it++){
        QTableWidgetItem* col_idx = new QTableWidgetItem(QString::number(ui->tableWidget->rowCount()),QTableWidgetItem::Type);
        QTableWidgetItem* col_err_line = new QTableWidgetItem(QString::number((*it)->get_error_row()),QTableWidgetItem::Type);
        QTableWidgetItem* col_err_col = new QTableWidgetItem(QString::number((*it)->get_error_col()),QTableWidgetItem::Type);
        QTableWidgetItem* col_err_desc = new QTableWidgetItem(QString::fromStdString((*it)->get_error_desc()),QTableWidgetItem::Type);

        col_idx->setFlags(col_idx->flags() & ~Qt::ItemIsEditable);
        col_err_line->setFlags(col_err_line->flags() & ~Qt::ItemIsEditable);
        col_err_col->setFlags(col_err_col->flags() & ~Qt::ItemIsEditable);
        col_err_desc->setFlags(col_err_desc->flags() & ~Qt::ItemIsEditable);

        m_tbl_len_map[ui->tableWidget->rowCount()] = (*it)->get_tok()->get_raw_tok().length();

        ui->tableWidget->insertRow(ui->tableWidget->rowCount());
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, col_idx);
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, col_err_line);
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, col_err_col);
        ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 3, col_err_desc);
    }

    delete pCtx;
}

void MainWindow::on_textEdit_textChanged()
{
    m_is_changed = true;
    update_title();
}

void MainWindow::tableItemClicked(QTableWidgetItem* item)
{
   auto item2 = item;
   item2->background();
    /* do some stuff with item */
}

void MainWindow::on_tableWidget_cellDoubleClicked(int row, int column)
{
    int idx = stoi(ui->tableWidget->item(row, 0)->text().toStdString(), 0);
    int line = stoi(ui->tableWidget->item(row, 1)->text().toStdString(), 0);
    int col = stoi(ui->tableWidget->item(row, 2)->text().toStdString(), 0);

    QTextBlock b = ui->textEdit->document()->findBlockByLineNumber(line-1);

    if (b.isValid() && m_tbl_len_map.find(idx) != m_tbl_len_map.end()) {
        QTextCursor c = QTextCursor(b);
        c.setPosition(c.position() + col);
        c.setPosition(c.position() + m_tbl_len_map[idx], QTextCursor::KeepAnchor);
        ui->textEdit->setTextCursor(c);
    }

}

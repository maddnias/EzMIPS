#include "editor_window.h"
#include "ui_editor_window.h"
#include "mips_highlighter.h"
#include <QBrush>
#include <QMessageBox>
#include <QMenuBar>
#include "source_file.h"
#include "tokenizer.h"

EditorWindow::EditorWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditorWindow)
{
    ui->setupUi(this);
    setup_text_editor();
    setup_error_table();

}

EditorWindow::~EditorWindow()
{
    delete ui;
}

void EditorWindow::setup_text_editor(){
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

void EditorWindow::setup_error_table(){
    ui->tableWidget->setColumnCount(4);

    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);

    QTableWidgetItem* col_num = new QTableWidgetItem(QString("Err #"),QTableWidgetItem::Type);
    QTableWidgetItem* col_line = new QTableWidgetItem(QString("Line"),QTableWidgetItem::Type);
    QTableWidgetItem* col_col = new QTableWidgetItem(QString("Column"),QTableWidgetItem::Type);
    QTableWidgetItem* col_err = new QTableWidgetItem(QString("Error"),QTableWidgetItem::Type);


    ui->tableWidget->setHorizontalHeaderItem(0,col_num);
    ui->tableWidget->setHorizontalHeaderItem(1, col_line);
    ui->tableWidget->setHorizontalHeaderItem(2, col_col);
    ui->tableWidget->setHorizontalHeaderItem(3, col_err);
    //ui->tableWidget->setItem(0, 0, col_test);
}

void EditorWindow::on_tableWidget_itemDoubleClicked(QTableWidgetItem *item)
{
    QMessageBox *r = new QMessageBox();
    r->setText(item->text());
    r->show();
}

void EditorWindow::on_pushButton_clicked()
{
#if _WIN32
    source_file f("C:\\TestScript.txt");
#elif __linux__
    source_file f("TestScript.txt");
#endif
    f.load();
    mips_tokenizer t;
    auto test = t.parse_tokens(&f);

    for(auto it = test.begin();it != test.end();it++){
        if((*it)->get_tok_type() == TOKEN_TYPE::UNDEFINED_TOK){
             QTableWidgetItem* col_test1 = new QTableWidgetItem(QString::number(ui->tableWidget->rowCount()),QTableWidgetItem::Type);
             QTableWidgetItem* col_test2 = new QTableWidgetItem(QString::number((*it)->get_tok_row()+1),QTableWidgetItem::Type);
             QTableWidgetItem* col_test3 = new QTableWidgetItem(QString::number((*it)->get_tok_col()),QTableWidgetItem::Type);
             QTableWidgetItem* col_test4 = new QTableWidgetItem(QString("Undefined token: ") + QString::fromStdString((*it)->get_raw_tok()),QTableWidgetItem::Type);
             ui->tableWidget->insertRow(ui->tableWidget->rowCount());
             ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 0, col_test1);
             ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 1, col_test2);
             ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 2, col_test3);
             ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, 3, col_test4);
        }

    }
}

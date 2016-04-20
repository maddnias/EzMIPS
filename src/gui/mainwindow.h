#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include "source_file.h"
#include "../parser/parser_error.h"
#include <map>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void setup_text_editor();
    void setup_error_table();

    void update_title();
    void save_with_dialog();

    void tableItemClicked(QTableWidgetItem* item);

    std::map<int, int> m_tbl_len_map;

    QAction *m_newAct;

    source_file *m_src_file;
    bool m_is_changed;
    Ui::MainWindow *ui;

private slots:
    void newFile();
    void on_actionNew_triggered();
    void on_actionSave_triggered();
    void on_actionAssemble_triggered();
    void on_actionRun_triggered();
    void on_textEdit_textChanged();
    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);
    void on_tableWidget_cellDoubleClicked(int row, int column);
};

#endif // MAINWINDOW_H

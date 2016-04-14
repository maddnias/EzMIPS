#ifndef EDITOR_WINDOW_H
#define EDITOR_WINDOW_H

#include <QWidget>
#include <QTableWidgetItem>

namespace Ui {
class EditorWindow;
}

class EditorWindow : public QWidget
{
    Q_OBJECT

public:
    explicit EditorWindow(QWidget *parent = 0);
    ~EditorWindow();

private slots:
    void on_tableWidget_itemDoubleClicked(QTableWidgetItem *item);

    void on_pushButton_clicked();

private:
    void setup_text_editor();
    void setup_error_table();
    Ui::EditorWindow *ui;
};

#endif // EDITOR_WINDOW_H

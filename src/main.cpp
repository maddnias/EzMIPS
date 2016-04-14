#include "source_file.h"
#include <chrono>
#include <QMessageBox>
#include <QApplication>
#include <QDebug>
#include "tokenizer.h"
#include <iostream>
#include "gui/editor_window.h"
#include "gui/mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

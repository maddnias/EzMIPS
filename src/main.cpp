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
#if _WIN32
    source_file f(L"C:\\TestScript.txt");
#elif __linux__
    source_file f("TestScript.txt");
#endif
    f.load();
    mips_tokenizer t;
    auto test = t.parse_tokens(&f);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

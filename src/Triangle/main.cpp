#include "mainwindow.h"
#include <stdio.h>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    printf("Hoi!\n");

    return a.exec();
}

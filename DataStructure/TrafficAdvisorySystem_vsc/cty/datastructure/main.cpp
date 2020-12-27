#include "mainwindow.h"
#include "Class.h"
#include <QApplication>

Citys cities;

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("交通咨询系统");
    w.show();
    return a.exec();
}

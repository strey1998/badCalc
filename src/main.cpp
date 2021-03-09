#include "mainwindow.h"

#include <QApplication>

#include "calculator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w(0, new Calculator());
    w.show();
    w.setWindowTitle("wCalc");
    return a.exec();
}

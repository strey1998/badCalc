#include "mainwindow.h"

#include <QApplication>

#include "calculator.h"

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
  #include <Windows.h>
#endif

int main(int argc, char *argv[])
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
      FreeConsole();
    #endif
    QApplication a(argc, argv);
    MainWindow w(0, new Calculator());
    w.show();
    w.setWindowTitle("wCalc");
    return a.exec();
}

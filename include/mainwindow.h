#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "calculator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, Calculator* calc = nullptr);
    ~MainWindow();

private slots:
    void onDigitClicked(int digit);
    void onOperationClicked(Operation op);
    void on_btnNum0_clicked();
    void on_btnNum1_clicked();
    void on_btnNum2_clicked();
    void on_btnNum3_clicked();
    void on_btnNum4_clicked();
    void on_btnNum5_clicked();
    void on_btnNum6_clicked();
    void on_btnNum7_clicked();
    void on_btnNum8_clicked();
    void on_btnNum9_clicked();
    void on_btnDecimal_clicked();
    void on_btnOpAdd_clicked();
    void on_btnOpSub_clicked();
    void on_btnOpMult_clicked();
    void on_btnOpDiv_clicked();
    void on_btnOpEq_clicked();
    void on_btnClear_clicked();
    void on_btn42_clicked();

private:
    Ui::MainWindow *ui;
    Calculator* calc;
    void updateDisplay();
};
#endif // MAINWINDOW_H

#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, Calculator* calc) :
    QMainWindow(parent),
    calc(calc),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->btnNum7->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateDisplay() {
    ui->lcdDisplay->display(calc->getNum());
}

void MainWindow::onDigitClicked(int digit) {
    calc->typeDigit(digit);
    updateDisplay();
}

void MainWindow::onOperationClicked(Operation op) {
    calc->queueOperation(op);
    updateDisplay();
}

void MainWindow::on_btnNum0_clicked()
{
    onDigitClicked(0);
}


void MainWindow::on_btnNum1_clicked()
{
    onDigitClicked(1);
}

void MainWindow::on_btnNum2_clicked()
{
    onDigitClicked(2);
}

void MainWindow::on_btnNum3_clicked()
{
    onDigitClicked(3);
}

void MainWindow::on_btnNum4_clicked()
{
    onDigitClicked(4);
}

void MainWindow::on_btnNum5_clicked()
{
    onDigitClicked(5);
}

void MainWindow::on_btnNum6_clicked()
{
    onDigitClicked(6);
}

void MainWindow::on_btnNum7_clicked()
{
    onDigitClicked(7);
}

void MainWindow::on_btnNum8_clicked()
{
    onDigitClicked(8);
}

void MainWindow::on_btnNum9_clicked()
{
    onDigitClicked(9);
}

void MainWindow::on_btnDecimal_clicked()
{
    calc->typeDecimal();
    updateDisplay();
}

void MainWindow::on_btnOpAdd_clicked()
{
    onOperationClicked(Operation::Add);
}

void MainWindow::on_btnOpSub_clicked()
{
    onOperationClicked(Operation::Subtract);
}

void MainWindow::on_btnOpMult_clicked()
{
    onOperationClicked(Operation::Multiply);
}

void MainWindow::on_btnOpDiv_clicked()
{
    onOperationClicked(Operation::Divide);
}

void MainWindow::on_btnOpNeg_clicked()
{
    calc->negateNum();
    updateDisplay();
}

void MainWindow::on_btnOpEq_clicked()
{
    calc->equals();
    updateDisplay();
}

void MainWindow::on_btnClear_clicked()
{
    if(calc->clear()) {
        delete calc;
        calc = new Calculator();
    }
    updateDisplay();
}

void MainWindow::on_btn42_clicked()
{
    calc->fortytwo();
    updateDisplay();
}

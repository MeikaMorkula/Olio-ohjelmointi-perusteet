#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_CountButton_clicked()
{
    QString displayNum = ui->lineEdit->text();
    int num = displayNum.toInt();
    num++;
    QString retNum  = QString::number(num);
    ui->lineEdit->setText(retNum);
}


void MainWindow::on_ResetButton_clicked()
{
ui->lineEdit->setText("0");
}


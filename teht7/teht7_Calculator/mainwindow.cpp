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

void MainWindow::numberClickHandler(int n)
{
    qDebug()<<n;
     qDebug()<<"Tila: "<<state;


    if(state == 1)
    {
         activeStateController(0);

        //mahdollistetaan isompien lukujen käyttö, esim 11+33
        QString number = number1  + QString::number(n);

        ui->Num1->setText(number);
        number1=number;
        activeStateController(1);
    }
    else if(state == 2)
    {
        ui->Num1->setEnabled(false);
        ui->Num2->setEnabled(true);

        QString number =  number2  + QString::number(n);
        ui->Num2->setText(number);
        number2=number;


        //Aktivoidaan enter nappi vasta kun molemmissa kentissä on numero
        activeStateController(2);;
    }

}

void MainWindow::operandHander(int o)
{
    if(state==1)
    {
        state++;
    }

    operand = o;
}

void MainWindow::resetLineEdits()
{
    ui->Num1->clear();
    ui->Num2->clear();
    ui->Result->clear();
}

void MainWindow::activeStateController(int n)
{


    //Ei voida käyttää state-muuttujaa järkevästi tämän hallintaan, sen takia, että state muuttuu operaation valitsemisessa enterin sijaan.
    switch(n)
    {
     case 0:
        ui->Num1->setEnabled(true);
        ui->Num2->setEnabled(false);
        ui->Enter->setEnabled(false);
        ui->Add->setEnabled(false);
        ui->Div->setEnabled(false);
        ui->Sub->setEnabled(false);
        ui->Mul->setEnabled(false);
        break;

     case 1:
         ui->Num1->setEnabled(false);
         ui->Num2->setEnabled(true);
         ui->Add->setEnabled(true);
         ui->Div->setEnabled(true);
         ui->Sub->setEnabled(true);
         ui->Mul->setEnabled(true);
         break;

     case 2:
       ui->Enter->setEnabled(true);
     }
}

void MainWindow::on_N1_clicked()
{
    QString str = ui->N1->text();
    int num = str.toInt();
    numberClickHandler(num);
}

void MainWindow::on_N2_clicked()
{
    QString str = ui->N2->text();
    int num = str.toInt();
    numberClickHandler(num);
}

void MainWindow::on_N3_clicked()
{
    QString str = ui->N3->text();
    int num = str.toInt();
    numberClickHandler(num);
}

void MainWindow::on_N4_clicked()
{
    QString str = ui->N4->text();
    int num = str.toInt();
    numberClickHandler(num);
}

void MainWindow::on_N5_clicked()
{
    QString str = ui->N5->text();
    int num = str.toInt();
    numberClickHandler(num);
}

void MainWindow::on_N6_clicked()
{
    QString str = ui->N6->text();
    int num = str.toInt();
    numberClickHandler(num);
}

void MainWindow::on_N7_clicked()
{
    QString str = ui->N7->text();
    int num = str.toInt();
    numberClickHandler(num);
}

void MainWindow::on_N8_clicked()
{
    QString str = ui->N8->text();
    int num = str.toInt();
    numberClickHandler(num);
}

void MainWindow::on_N9_clicked()
{
    QString str = ui->N9->text();
    int num = str.toInt();
    numberClickHandler(num);
}

void MainWindow::on_N0_clicked()
{
    QString str = ui->N0->text();
    int num = str.toInt();
    numberClickHandler(num);
}

void MainWindow::on_Add_clicked()
{
    operandHander(0);

}

void MainWindow::on_Sub_clicked()
{
    operandHander(1);
}

void MainWindow::on_Mul_clicked()
{
    operandHander(2);
}

void MainWindow::on_Div_clicked()
{
    operandHander(3);
}

void MainWindow::on_Clear_clicked()
{
    state=1;
    number1="";
    number2="";
    resetLineEdits();
    activeStateController(0);
}

void MainWindow::on_Enter_clicked()
{
    state++;
    if(state ==3)
    {
        state=1;
        number1=ui->Num1->text();
        number2=ui->Num2->text();
        float n1 = number1.toFloat();
        float n2 = number2.toFloat();

        switch(operand)
        {
        case 0:
            result = n1+n2;
            qDebug()<<n1 <<"+"<<n2 <<" = "<<result;
            break;
        case 1:
            result = n1-n2;
            qDebug()<<n1 <<"-"<<n2 <<" = "<<result;
            break;
        case 2:
            result = n1*n2;
            qDebug()<<n1 <<"*"<<n2 <<" = "<<result;
            break;
        case 3:
            result = n1/n2;
            qDebug()<<n1 <<"/"<<n2 <<" = "<<result;
            break;
        }


        QString res = QString::number(result);

        ui->Result->setText(res);

        qDebug()<<res;
    }
    else{qDebug()<<"Something went wrong";}



}


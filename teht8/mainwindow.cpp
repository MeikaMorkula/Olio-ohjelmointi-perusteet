#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //disabloidaan aloitusnappi niin kauan kun aikaa ei ole valittu
    ui->StartGameBtn->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
    if(pQTimer)
    {
        pQTimer->stop();
        delete pQTimer;
        pQTimer=nullptr;
    }

}

void MainWindow::on_Player1SwBtn_clicked()
{
    currentPlayer = 2;
    setCurrentPlayerText();
}


void MainWindow::on_Player2SwBtn_clicked()
{
    currentPlayer = 1;
    setCurrentPlayerText();
}


void MainWindow::on_Btn120Sec_clicked()
{
    gameTime = 120;

    qDebug()<<gameTime;
    ui->StartGameBtn->setEnabled(true);
    ui->P1ProgressBar->setRange(0, gameTime);
    ui->P2ProgressBar->setRange(0, gameTime);
    ui->P1ProgressBar->setValue(gameTime);
    ui->P2ProgressBar->setValue(gameTime);

    setGameInfoText("Ready To Play!");
}


void MainWindow::on_Btn5Min_clicked()
{
    //5min = 300sec
    gameTime = 300;
    qDebug()<<gameTime;
    ui->StartGameBtn->setEnabled(true);
    ui->P1ProgressBar->setRange(0, gameTime);
    ui->P2ProgressBar->setRange(0, gameTime);
    ui->P1ProgressBar->setValue(gameTime);
    ui->P2ProgressBar->setValue(gameTime);

    setGameInfoText("Ready To Play!");
}


void MainWindow::on_StartGameBtn_clicked()
{
    //pelaajien asetus
    player1Time = gameTime;
    player2Time = gameTime;
    currentPlayer=1;
    setCurrentPlayerText();

    qDebug()<<"Game Started With "<< gameTime<< " Seconds Of Playtime";

    pQTimer = new QTimer(this);

    connect(pQTimer, &QTimer::timeout, this, &MainWindow::updateProgressBar);
    pQTimer->setInterval(1000);
    pQTimer->start();
    qDebug()<<"Timer started";

    setGameInfoText("Game Ongoing");

    //disabloidaan start nappi pelin ajaksi
    ui->StartGameBtn->setEnabled(false);

    //Disabloidaan ajan valinta pelin ajaksi
    ui->Btn120Sec->setEnabled(false);
    ui->Btn5Min->setEnabled(false);
}


void MainWindow::on_EndGameBtn_clicked()
{
    if(pQTimer)
    {
        pQTimer->stop();
        delete pQTimer;
        pQTimer=nullptr;
        qDebug()<<"Timer stopped, Game Ended";
    }

    ui->Btn120Sec->setEnabled(true);
    ui->Btn5Min->setEnabled(true);

    player1Time=0;
    player2Time=0;


    setGameInfoText("Start a new game by selecting playtime");
}

void MainWindow::updateProgressBar()
{

    if(currentPlayer == 1)
    {
        player1Time = player1Time-1;
        ui->P1ProgressBar->setValue(player1Time);

        if(player1Time == 0)
        {
            pQTimer->stop();
            delete pQTimer;
            pQTimer=nullptr;


            ui->Btn120Sec->setEnabled(true);
            ui->Btn5Min->setEnabled(true);

            qDebug()<<"Timer stopped, Game Ended";
            setGameInfoText("Player 2 WON");
        }
    }
    else if (currentPlayer == 2)
    {
        player2Time = player2Time-1;
        ui->P2ProgressBar->setValue(player2Time);
        if(player2Time == 0)
        {
            pQTimer->stop();
            delete pQTimer;
            pQTimer=nullptr;


            ui->Btn120Sec->setEnabled(true);
            ui->Btn5Min->setEnabled(true);

            qDebug()<<"Timer stopped, Game Ended";
            setGameInfoText("Player 1 WON");
        }
    }

}

void MainWindow::setGameInfoText(QString labelText)
{
    ui->label->setText(labelText);
}

void MainWindow::setCurrentPlayerText()
{
    //Hienouden vuoksi lisätään pelinäkymään nykyinen pelaaja
    QString curPlayer = "Current Player: ";
    curPlayer.append(QString::number(currentPlayer));
    ui->CurrentplayerLabel->setText(curPlayer);
}



#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Player1SwBtn_clicked();

    void on_Player2SwBtn_clicked();

    void on_Btn120Sec_clicked();

    void on_Btn5Min_clicked();

    void on_StartGameBtn_clicked();

    void on_EndGameBtn_clicked();

private:
    Ui::MainWindow *ui;

    void updateProgressBar();
    void setGameInfoText(QString labelText);
    void setCurrentPlayerText();

    short player1Time;
    short player2Time;
    short currentPlayer;
    short gameTime;
    QTimer *pQTimer = nullptr;
};
#endif // MAINWINDOW_H

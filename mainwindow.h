#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "countdown.h"
#include <QAbstractButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void paintEvent(QPaintEvent *event);

private slots:
    void on_pushButton_clicked();
    void receive_countd(int code);//接收传递过来的数据的槽
    void on_actionABOUT_triggered();
    void on_actionHELP_triggered();
    void onButtonClicked(QAbstractButton *button);

private:
    Ui::MainWindow *ui;
    countdown countd;


};

#endif // MAINWINDOW_H

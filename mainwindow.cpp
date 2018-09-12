#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>
#include <QDateTime>
#include <QTime>
#include <QButtonGroup>
#include "countdown.h"
int code;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Tboot->setText("启动时间："+QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss ddd"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    countdown *countd= new countdown;
    connect(countd, SIGNAL(send_countd(int)), this, SLOT(receive_countd(int)));
     //关联 Main <- countdown1

    countd->show();
}

void MainWindow::onButtonClicked(QAbstractButton *button)
{
     qDebug() << "Clicked Button : " << button->text();

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);             // 创建QPainter一个对象
    //if () {} else {}

    QRectF rect(206,93,80,30);
    painter.setBrush(Qt::SolidPattern);
    painter.drawRoundedRect(rect ,16,16);
}
void MainWindow::receive_countd(int code)
{
    ui->lcdNumber->display(code);  //获取传递过来的数据
}

void MainWindow::on_actionABOUT_triggered()
{
    QMessageBox::about(this, tr("About folderLists"),
          tr("<h1> ForEyes </h1>"

          "<p><h4>Release 0.1</h4>"
          "<p>Copyright ©2019 jasonYpretty.All rights reserved."
          "<p>by jasonYpretty"
          "<p>😋 https://github.com/jasonYpretty"
                    ));
}

void MainWindow::on_actionHELP_triggered()
{
    QMessageBox::about(this, tr("Help"),
             tr("<h1> Help </h1>"
             "<p><h4>保护眼睛</h4>"
             "<p>HAHAHHAHHAHHAHAHHAHAHAHHAHAHA"
             "<p><h4>倒计时 等功能</h4>"
             "<p>保护眼睛"

                ));
}

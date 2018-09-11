#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QMouseEvent>
#include "countdown.h"
int code;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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

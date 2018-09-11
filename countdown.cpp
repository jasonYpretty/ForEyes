#include "countdown.h"
#include "ui_countdown.h"
#include <QLayout>
#include <QMessageBox>
#include <QSlider>
#include <QTimer>
#include <QComboBox>
#include <QtCore>
#include <QDebug>
#include <string>
#include <QString>
#include <QSettings>
#include <QTableWidget>
#include "warn_countdown1.h"
using namespace std;

countdown::countdown(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::countdown)
{
    ui->setupUi(this);
    setWindowFlags(Qt::WindowStaysOnTopHint);
    ui->label_time->setText(QString::number(ui->slider_time->value()*10+ui->dial_time->value(), 'f', 0));
    timer = new QTimer(this);

    connect(timer, SIGNAL(timeout()), this, SLOT(warn()));  //倒计时的信号槽
}

countdown::~countdown()
{
    delete ui;
}

void countdown::on_dial_time_valueChanged(int value)
{
    ui->label_time->setText(QString::number(value+ui->slider_time->value()*10, 'f', 0));
}
void countdown::on_slider_time_valueChanged(int value)
{
    ui->label_time->setText(QString::number(value*10+ui->dial_time->value(), 'f', 0));
}
//设置定时时间

void countdown::countTime(){
}


void countdown::on_tab_countd_currentChanged(int index)
{
   qDebug("c index: %d" ,index);
}

void countdown::on_pushButton_countTime_clicked()
{
    int num = ui->slider_time->value()+ui->dial_time->value();  //到时候得再乘以10
    num *= 1000;
    timer->start(num);
    emit send_countd(1); //positive 发送状态码
}

void countdown::receiveData(QString data)
{
   wc1_wT = data;  //获取传递过来的数据
}
void countdown::warn(){
    on_pushButton_clicked(); //播放声音，未完成

    if (ui->checkBox_1->isChecked() == true){
        QString str = "喝水去---!";
        if(wc1_wT != NULL) QMessageBox::information(this, "ForEyes-计时器", wc1_wT);
        else QMessageBox::information(this, "ForEyes-计时器", str);
    }else {
        QMessageBox::information(this, "ForEyes-timer","这是没勾选的测试!");
    };
    timer->stop();
    on_pushButton_countTime_clicked();
}

void countdown::on_toolButton_clicked()
{
    warn_countdown1 *wc1= new warn_countdown1;
    connect(wc1, SIGNAL(sendData(QString)), this, SLOT(receiveData(QString)));
    //关联 countdown <- warn_cd1
    wc1->show();
}

void countdown::on_playsound_currentIndexChanged(int index)
{
    ui->lcdNumber->display(index);
}

void countdown::on_pushButton_clicked()
{
    QString filename = "qrc:/src/src/"+QString::number(ui->playsound->currentIndex())+".mp3";//1.mp3为ding
    player = new QMediaPlayer(this);
    player->setMedia(QMediaContent(QUrl(filename)));
    player->play();
    //播放对应 音频
}

void countdown::receive_c1(int code){

   if(code == 0) {
     timer->stop();;
   }else{
     on_pushButton_countTime_clicked();
   }
}

void countdown::on_quit_clicked()
{
   this->close(); //关闭设置窗口
}

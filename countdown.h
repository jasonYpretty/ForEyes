#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <QWidget>
#include <QLineEdit>
#include <QMediaPlayer>
#include <QDialog>

namespace Ui {
class countdown;
}

class countdown : public QWidget
{
    Q_OBJECT

public:
    explicit countdown(QWidget *parent = 0);
    ~countdown();
    QString wc1_wT; //警告语句

private:
    Ui::countdown *ui; 
    QTimer *timer;
    QLineEdit *edit;
    QMediaPlayer *player;

private slots:
    void on_tab_countd_currentChanged(int index);
    void on_dial_time_valueChanged(int value);
    void on_slider_time_valueChanged(int value);
    void countTime();
    void warn();
    void on_pushButton_clicked();
    void on_pushButton_countTime_clicked();
    void on_toolButton_clicked();
   // void textChanged(QString str);
    void on_playsound_currentIndexChanged(int index);
    void receiveData(QString data);
    void receive_c1(int code);
    void on_quit_clicked();

signals:
    void send_countd(int); //countdown->main
};

#endif // COUNTDOWN_H

#ifndef WARN_COUNTDOWN1_H
#define WARN_COUNTDOWN1_H

#include <QDialog>

namespace Ui {
class warn_countdown1;
}

class warn_countdown1 : public QDialog
{
    Q_OBJECT

public:
    explicit warn_countdown1(QWidget *parent = 0);
    ~warn_countdown1();

private slots:
    void on_buttonBox_accepted();

signals:
    void sendData(QString);   //用来传递数据的信号

private:
    Ui::warn_countdown1 *ui;
};

#endif // WARN_COUNTDOWN1_H

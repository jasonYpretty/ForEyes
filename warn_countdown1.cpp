#include "warn_countdown1.h"
#include "ui_warn_countdown1.h"

warn_countdown1::warn_countdown1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::warn_countdown1)
{
    ui->setupUi(this);
}

warn_countdown1::~warn_countdown1()
{
    delete ui;
}

void warn_countdown1::on_buttonBox_accepted()
{
    QString data = ui->lineEdit->text();
    emit sendData(data);
}

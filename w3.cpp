#include "w3.h"
#include "ui_w3.h"
#include<qmessagebox.h>
w3::w3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::w3)
{
    ui->setupUi(this);
    sigmaclose();
}

w3::~w3()
{
    delete ui;
}
void w3::sigmashow()
{
    ui->label->show();
    ui->spinBox_2->show();
}
void w3::sigmaclose()
{
    ui->label->close();
    ui->spinBox_2->close();
}



void w3::on_comboBox_3_activated(const QString &arg1)
{
    if(arg1=="高斯滤波")
    {
        sigmashow();
    }
    else {
        sigmaclose();
    }

}

void w3::on_pushButton_3_clicked()
{
    if(ui->comboBox_3->currentText()=="高斯滤波")
    {
        emit sendinfo("高斯滤波",ui->spinBox->value(),ui->spinBox_2->value());
    }
    else {
        emit sendinfo(ui->comboBox_3->currentText(),ui->spinBox->value(),NULL);
    }

}

void w3::on_pushButton_clicked()
{
    emit save(1);

QMessageBox::information(this, "提示", tr("操作已保存"),
                         QMessageBox::Yes, QMessageBox::Yes);
}

void w3::on_pushButton_2_clicked()
{
    emit save(2);
    QMessageBox::information(this, "提示", tr("重置完毕"),
                             QMessageBox::Yes, QMessageBox::Yes);
}

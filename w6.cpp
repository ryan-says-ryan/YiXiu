#include "w6.h"
#include "ui_w6.h"
#include<qmessagebox.h>
w6::w6(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::w6)
{
    ui->setupUi(this);
    nclose();
    mclose();
}

w6::~w6()
{
    delete ui;
}

void w6::nshow()
{
    ui->label->show();
    ui->spinBox_2->show();
}
void w6::nclose()
{
    ui->label->close();
    ui->spinBox_2->close();
}
void w6::mshow()
{
    ui->label_8->show();
    ui->spinBox_3->show();
}
void w6::mclose()
{
    ui->label_8->close();
    ui->spinBox_3->close();
}

void w6::on_comboBox_3_activated(const QString &arg1)
{
    if(arg1=="巴特沃斯滤波")
        {
        nshow();
    }
    else {
        nclose();
    }
}

void w6::on_comboBox_4_activated(const QString &arg1)
{
    if(arg1=="带通滤波"||arg1=="带阻滤波")
    {
        mshow();
    }
    else {
        mclose();
    }
}

void w6::on_pushButton_3_clicked()
{
    if(ui->comboBox_3->currentText()=="巴特沃斯滤波")
        {
        if(ui->comboBox_4->currentText()=="带通滤波"||ui->comboBox_4->currentText()=="带阻滤波")
        {
            emit sendinfo(ui->comboBox_3->currentText(),ui->comboBox_4->currentText(),ui->spinBox->value(),
                          ui->spinBox_2->value(),ui->spinBox_3->value());
        }
        else {
            emit sendinfo(ui->comboBox_3->currentText(),NULL,ui->spinBox->value(),
                          ui->spinBox_2->value(),NULL);
        }

    }
    else {
        if(ui->comboBox_4->currentText()=="带通滤波"||ui->comboBox_4->currentText()=="带阻滤波")
        {
            emit sendinfo(ui->comboBox_3->currentText(),ui->comboBox_4->currentText(),ui->spinBox->value(),
                          NULL,ui->spinBox_3->value());
        }
        else {
            emit sendinfo(ui->comboBox_3->currentText(),NULL,ui->spinBox->value(),
                          NULL,NULL);
        }
    }


}

void w6::on_pushButton_clicked()
{
    emit save(1);

QMessageBox::information(this, "提示", tr("操作已保存"),
                         QMessageBox::Yes, QMessageBox::Yes);
}

#include "w1.h"
#include "ui_w1.h"
#include"qdebug.h"
#include<qmessagebox.h>

w1::w1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::w1)
{
    ui->setupUi(this);
    fzclose();
    ezhclose();
    mlclose();
    hdshow();
}

w1::~w1()
{
    delete ui;
}

void w1::hdshow()
{
    ui->label_8->show();
    ui->comboBox_4->show();
}
void w1::hdclose()
{
    ui->label_8->close();
    ui->comboBox_4->close();
}
void w1::fzshow()
{

}
void w1::fzclose()
{

}
void w1::ezhshow()
{
    ui->label_7->show();
    ui->spinBox_3->show();
}
void w1::ezhclose()
{
    ui->label_7->close();
    ui->spinBox_3->close();
}
void w1::mlshow()
{
    ui->label->show();
    ui->label_2->show();
    ui->spinBox->show();
    ui->doubleSpinBox->show();
}
void w1::mlclose()
{
    ui->label->close();
    ui->label_2->close();
    ui->spinBox->close();
    ui->doubleSpinBox->close();
}

void w1::on_comboBox_3_activated(const QString &arg1)
{
    if(arg1=="幂律变换")
    {
        hdclose();
        ezhclose();
        mlshow();
    }
    if(arg1=="图像灰度化")
    {
        mlclose();
        ezhclose();
        hdshow();
    }
    if(arg1=="图像反转")
    {
        mlclose();
        ezhclose();
        hdclose();
    }
    if(arg1=="图像二值化")
    {
        mlclose();
        hdclose();
        ezhshow();
    }


}

void w1::on_graybtn_clicked()
{
    if(ui->comboBox_3->currentText()=="图像灰度化")
    {
        emit sendinfo("图像灰度化",ui->comboBox_4->currentText(),NULL,NULL,NULL);

        qDebug()<<"emit 1";

    }
    else if(ui->comboBox_3->currentText()=="图像反转")
    {
        emit sendinfo("图像反转",NULL,NULL,NULL,NULL);
        qDebug()<<"emit 2";
    }
    else if(ui->comboBox_3->currentText()=="图像二值化")
    {
        emit sendinfo("图像二值化",NULL,ui->spinBox_3->value(),NULL,NULL);
        qDebug()<<"emit 3";
    }
    else if(ui->comboBox_3->currentText()=="幂律变换")
    {
        emit sendinfo("幂律变换",NULL,NULL,ui->spinBox->value(),ui->doubleSpinBox->value());
        qDebug()<<"emit 4"<<ui->doubleSpinBox->value();
    }


}

void w1::on_pushButton_clicked()
{
    emit save(1);
    QMessageBox::information(this, "提示", tr("操作已保存"),
                             QMessageBox::Yes, QMessageBox::Yes);
}

void w1::on_pushButton_2_clicked()
{
    emit save(2);
    QMessageBox::information(this, "提示", tr("重置完毕"),
                             QMessageBox::Yes, QMessageBox::Yes);
}

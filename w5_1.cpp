#include "w5_1.h"
#include "ui_w5_1.h"
#include<qmessagebox.h>
w5_1::w5_1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::w5_1)
{
    ui->setupUi(this);
    jyclose();
    fcshow();
}

w5_1::~w5_1()
{
    delete ui;
}

void w5_1::jyshow()
{
    ui->label_2->show();
    ui->spinBox->show();
}
void w5_1::jyclose()
{
    ui->label_2->close();
    ui->spinBox->close();
}
void w5_1::fcshow()
{
    ui->label_5->show();
    ui->label_7->show();
    ui->spinBox_2->show();
    ui->spinBox_3->show();
}
void w5_1::fcclose()
{
    ui->label_5->close();
    ui->label_7->close();
    ui->spinBox_2->close();
    ui->spinBox_3->close();
}

void w5_1::on_comboBox_3_activated(const QString &arg1)
{
    if(arg1=="椒盐噪声")
    {
        fcclose();
        jyshow();
    }
    else {
        jyclose();
        fcshow();
    }
}

void w5_1::on_pushButton_3_clicked()
{
    if(ui->comboBox_3->currentText()=="椒盐噪声")
    {
        emit sendinfo("椒盐噪声",NULL,NULL,ui->spinBox->value());
    }
    else {
        emit sendinfo(ui->comboBox_3->currentText(),ui->spinBox_2->value(),ui->spinBox_3->value(),NULL);
    }
}

void w5_1::on_pushButton_clicked()
{
    emit save(1);

QMessageBox::information(this, "提示", tr("操作已保存"),
                         QMessageBox::Yes, QMessageBox::Yes);
}

void w5_1::on_pushButton_2_clicked()
{
    emit save(2);
    QMessageBox::information(this, "提示", tr("重置完毕"),
                             QMessageBox::Yes, QMessageBox::Yes);
}

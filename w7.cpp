#include "w7.h"
#include "ui_w7.h"
#include<qmessagebox.h>
w7::w7(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::w7)
{
    ui->setupUi(this);
    byclose();
}

w7::~w7()
{
    delete ui;
}

void w7::fgshow()
{
    ui->label_8->show();
    ui->comboBox_4->show();
}
void w7::fgclose()
{
    ui->label_8->close();
    ui->comboBox_4->close();
}
void w7::byshow()
{
    ui->label_9->show();
    ui->comboBox_5->show();
}
void w7::byclose()
{
    ui->label_9->close();
    ui->comboBox_5->close();
}

void w7::on_comboBox_3_activated(const QString &arg1)
{
    if(arg1=="图像分割")
        {
        byclose();
        fgshow();
    }
    else {
        fgclose();
        byshow();
    }
}

void w7::on_pushButton_3_clicked()
{
    if(ui->comboBox_3->currentText()=="图像分割")
        {
        emit sendinfo(ui->comboBox_3->currentText(),ui->comboBox_4->currentText(),NULL,
                      ui->spinBox->value());
    }
    else {
        emit sendinfo(ui->comboBox_3->currentText(),NULL,ui->comboBox_5->currentText(),
                      ui->spinBox->value());
    }

}

void w7::on_pushButton_clicked()
{
    emit save(1);

QMessageBox::information(this, "提示", tr("操作已保存"),
                         QMessageBox::Yes, QMessageBox::Yes);
}

void w7::on_pushButton_2_clicked()
{
    emit save(2);
    QMessageBox::information(this, "提示", tr("重置完毕"),
                             QMessageBox::Yes, QMessageBox::Yes);
}

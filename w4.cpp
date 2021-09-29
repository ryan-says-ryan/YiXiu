#include "w4.h"
#include "ui_w4.h"
#include<qmessagebox.h>
w4::w4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::w4)
{
    ui->setupUi(this);
}

w4::~w4()
{
    delete ui;
}

void w4::on_pushButton_3_clicked()
{
    emit sendinfo(ui->comboBox_3->currentText());
}

void w4::on_pushButton_clicked()
{
    emit save(1);

QMessageBox::information(this, "提示", tr("操作已保存"),
                         QMessageBox::Yes, QMessageBox::Yes);
}

void w4::on_pushButton_2_clicked()
{
    emit save(2);
    QMessageBox::information(this, "提示", tr("重置完毕"),
                             QMessageBox::Yes, QMessageBox::Yes);
}

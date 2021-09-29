#include "w0.h"
#include "ui_w0.h"

w0::w0(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::w0)
{
    ui->setupUi(this);
}

w0::~w0()
{
    delete ui;
}

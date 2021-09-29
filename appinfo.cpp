#include "appinfo.h"
#include "ui_appinfo.h"

appinfo::appinfo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::appinfo)
{
    ui->setupUi(this);
}

appinfo::~appinfo()
{
    delete ui;
}

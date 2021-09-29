#ifndef APPINFO_H
#define APPINFO_H

#include <QDialog>

namespace Ui {
class appinfo;
}

class appinfo : public QDialog
{
    Q_OBJECT

public:
    explicit appinfo(QWidget *parent = nullptr);
    ~appinfo();

private:
    Ui::appinfo *ui;
};

#endif // APPINFO_H

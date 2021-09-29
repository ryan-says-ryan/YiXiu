#ifndef W6_H
#define W6_H

#include <QWidget>

namespace Ui {
class w6;
}

class w6 : public QWidget
{
    Q_OBJECT

public:
    explicit w6(QWidget *parent = nullptr);
    void nshow();
    void nclose();
    void mshow();
    void mclose();

    ~w6();
signals:
    void sendinfo(QString,QString,int,int,int);//类型,类型，半径r，阶数n，带宽w
    void save(int);
private slots:
    void on_comboBox_3_activated(const QString &arg1);

    void on_comboBox_4_activated(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

private:
    Ui::w6 *ui;
};

#endif // W6_H

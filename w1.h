#ifndef W1_H
#define W1_H

#include <QWidget>

namespace Ui {
class w1;
}

class w1 : public QWidget
{
    Q_OBJECT

public:
    explicit w1(QWidget *parent = nullptr);
    void hdshow();
    void hdclose();
    void fzshow();
    void fzclose();
    void ezhshow();
    void ezhclose();
    void mlshow();
    void mlclose();
    ~w1();

signals:
    void sendinfo(QString,QString,int,int,double);//参数分别为图像灰度化..（4种）,最大值法（3）,阈值，c，y，无则null。
    void save(int);
private slots:
    void on_comboBox_3_activated(const QString &arg1);


    void on_graybtn_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::w1 *ui;
};

#endif // W1_H

#ifndef W5_1_H
#define W5_1_H

#include <QWidget>

namespace Ui {
class w5_1;
}

class w5_1 : public QWidget
{
    Q_OBJECT

public:
    explicit w5_1(QWidget *parent = nullptr);
    void jyshow();
    void jyclose();
    void fcshow();
    void fcclose();
    ~w5_1();
signals:
    void sendinfo(QString,float,float,int);//类型,均值，方差，密度
    void save(int);
private slots:
    void on_comboBox_3_activated(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::w5_1 *ui;
};

#endif // W5_1_H

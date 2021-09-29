#ifndef W4_H
#define W4_H

#include <QWidget>

namespace Ui {
class w4;
}

class w4 : public QWidget
{
    Q_OBJECT

public:
    explicit w4(QWidget *parent = nullptr);
    ~w4();
signals:
    void sendinfo(QString);//类型
    void save(int);
private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::w4 *ui;
};

#endif // W4_H

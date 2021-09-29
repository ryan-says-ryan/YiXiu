#ifndef W3_H
#define W3_H

#include <QWidget>

namespace Ui {
class w3;
}

class w3 : public QWidget
{
    Q_OBJECT

public:
    explicit w3(QWidget *parent = nullptr);

    void sigmashow();
    void sigmaclose();
    ~w3();

signals:
    void sendinfo(QString,int,float);//类型，size,sigma
    void save(int);
private slots:
    void on_comboBox_3_activated(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::w3 *ui;
};

#endif // W3_H

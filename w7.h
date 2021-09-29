#ifndef W7_H
#define W7_H

#include <QWidget>

namespace Ui {
class w7;
}

class w7 : public QWidget
{
    Q_OBJECT

public:
    explicit w7(QWidget *parent = nullptr);
    void fgshow();
    void fgclose();
    void byshow();
    void byclose();
    ~w7();
signals:
    void sendinfo(QString,QString,QString,int);//类型,类型，识别度
    void save(int);
private slots:
    void on_comboBox_3_activated(const QString &arg1);

    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::w7 *ui;
};

#endif // W7_H

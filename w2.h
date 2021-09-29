//直方图
#ifndef W2_H
#define W2_H

#include "form.h"
#include <QDebug>
#include <QImage>
//#include <QBarCategoryAxis>
//#include <QBarSeries>
//#include <QBarSet>
//#include <QChart>
//#include <QChartView>
//#include <QValueAxis>
#include <QMessageBox>
//一定要声明命名空间

//using namespace QtCharts;

namespace Ui {
class w2;
}

class w2 : public QWidget
{
    Q_OBJECT

public:

    w2(QWidget *parent = nullptr);
    //class form *ps;
    void ppshow();
    void ppclose();
    ~w2();
    //转灰度图
    QImage toGray(QImage *image);
signals:
    void sendinfo(QString,QString);//类型，path
    void save(int);
public slots:
    //生成灰度直方图
    //void showHistogram(QImage *grayimage);

    void setThisPic(QImage *image);

    void makePicAverage(QImage *image);
    void histMatch(QImage *image);
private slots:

    void on_ok_clicked();

    void on_pushButton_clicked();

    void on_comboBox_3_activated(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::w2 *ui;
    QImage *pic=new QImage;
    QStringList fileNames;
};

#endif // W2_H

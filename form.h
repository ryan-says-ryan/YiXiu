#ifndef FORM_H
#define FORM_H

#include <QMainWindow>
#include <QPalette>
#include <QWidget>
#include <QDebug>
#include <QKeyEvent>
#include<QFileDialog>
#include<QPixmap>
#include <QPainter>
#include <QImage>
#include<QScreen>
#include<vector>

#include "w0.h"
#include "w1.h"
#include "w2.h"
#include "w3.h"
#include "w4.h"

#include "w5_1.h"
#include "w6.h"
#include "w7.h"
namespace Ui {
class form;
}

class form : public QMainWindow
{
    Q_OBJECT

public:
    form(QWidget *parent = nullptr);
    ~form();
    bool eventFilter(QObject *obj, QMouseEvent *e);

signals:
    void sendPic(QImage* image);

protected:
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void resizeEvent(QResizeEvent *event) override;

private slots:
    //void showim(QImage);

    void on_openFile_triggered();

    void on_preBtn_clicked();

    void on_nextBtn_clicked();

    void on_enlargeBtn_clicked();

    void on_reduceBtn_clicked();

    void on_spinBtn_clicked();

    void on_mirrorBtn_clicked();

    void on_cutBtn_clicked();

    void on_grayBtn_clicked();

    void on_histBtn_clicked();

    void on_smoothBtn_clicked();

    void on_sharpenBtn_clicked();

    void on_noiseBtn_clicked();

    void on_filterBtn_clicked();

    void on_shapeBtn_clicked();

    void W1processing(QString,QString,int,int,double);//参数分别为图像灰度化..（4种）,最大值法（3）,阈值，c，y，无则null。
    void W2processing(QString,QString);//类型，path
    void W3processing(QString,int,float);//类型，size,sigma
    void W4processing(QString);//类型
    void W5processing(QString,float,float,int);//类型,均值，方差，密度
    void W6processing(QString,QString,int,int,int);//类型,类型，半径r，阶数n，带宽w
    void W7processing(QString,QString,QString,int);//类型,类型，识别度
    void W1save(int);
    void W2save(int);
    void W3save(int);
    void W4save(int);
    void W5save(int);
    void W6save(int);
    void W7save(int);

    void on_actiona_triggered();

    void on_actionabout_triggered();

private:
    Ui::form *ui;
    QWidget* forml=NULL;
    QWidget* now=NULL;
    int saved=1;
    QImage originalim;
    QImage displayim;
    QVector<QImage>ims;
    int loc=0;
    int mousePosX;//记录有效位置的X
    int mousePosY;//记录有效位置的Y
    bool mouseFlagX = false;//记录是否可以进行左右移动
    bool mouseFlagX1 = false;//记录是否可以进行左右移动
    bool mouseFlagY = false;//记录是否可以开始上下移动
    QImage *p1 = new QImage;
    QStringList fileNames;
    //初始界面
    class w0 *welcomeWg;
    //灰度参数界面
    class w1 *grayWg;
    //直方图
    class w2 *histWg;
    //平滑
    class w3 *smoothWg;
    //锐化
    class w4 *sharpenWg;
    //噪声
    class w5_1 *noiseWg;
    //滤波
    class w6 *filterWg;
    //彩图
    class w7 *shapeWg;
    //spin status
    int status=0;
};

#endif // FORM_H

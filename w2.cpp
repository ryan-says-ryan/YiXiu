//直方图
#include "w2.h"
#include "ui_w2.h"
#include<qmessagebox.h>



w2::w2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::w2)
{
    ui->setupUi(this);
    ppclose();
}
void w2::ppshow()
{
    ui->label->show();
    ui->label_2->show();
    ui->pushButton->show();
}
void w2::ppclose()
{
    ui->label->close();
    ui->label_2->close();
    ui->pushButton->close();
}



void w2::setThisPic(QImage *image)
{
    this->pic=image;
}

void w2::makePicAverage(QImage *image)
{
//    image=new QImage(fileName);
    QImage ImageAverage;
    ImageAverage=QImage(image->width(),image->height(),QImage::Format_ARGB32);
    int i,j;
    int width,height;
    width=image->width();
    height=image->height();
    QRgb rgb;
    int r[256],g[256],b[256];//原图各个灰度数量的统计
    int rtmp,gtmp,btmp,rj,gj,bj;
    float rPro[256],gPro[256],bPro[256];//原图各个灰度级的概率
    float rTemp[256],gTemp[256],bTemp[256];//均衡化后各个灰度级的概率
    int rJun[256],gJun[256],bJun[256];//均衡化后对应像素的值
    memset(r,0,sizeof(r));
    memset(g,0,sizeof(g));
    memset(b,0,sizeof(b));

    //获取原图各个灰度的数量
    for(i=0;i<width;i++)
    {
        for(j=0;j<height;j++)
        {
            rgb=image->pixel(i,j);
            r[qRed(rgb)]++;
            g[qGreen(rgb)]++;
            b[qBlue(rgb)]++;
        }
    }

    //获取原图各个灰度级的概率
    for(i=0;i<256;i++)
    {
        rPro[i]=(r[i]*1.0)/(width*height);
        gPro[i]=(g[i]*1.0)/(width*height);
        bPro[i]=(b[i]*1.0)/(width*height);
    }

    //均衡化后各个灰度级的概率，同时获取均衡化后对应像素的值
    for(i=0;i<256;i++)
    {
        if(i==0)
        {
            rTemp[0]=rPro[0];
            gTemp[0]=gPro[0];
            bTemp[0]=bPro[0];
        }
        else
        {
            rTemp[i]=rTemp[i-1]+rPro[i];
            gTemp[i]=gTemp[i-1]+gPro[i];
            bTemp[i]=bTemp[i-1]+bPro[i];
        }
        rJun[i]=(int)(255*rTemp[i]+0.5);
        gJun[i]=(int)(255*gTemp[i]+0.5);
        bJun[i]=(int)(255*bTemp[i]+0.5);
    }

    for(i=0;i<width;i++)
    {
        for(j=0;j<height;j++)
        {
            rgb=image->pixel(i,j);
            rtmp=qRed(rgb);
            gtmp=qGreen(rgb);
            btmp=qBlue(rgb);
            rj=rJun[rtmp];
            gj=gJun[gtmp];
            bj=bJun[btmp];
            ImageAverage.setPixel(i,j,qRgb(rj,gj,bj));
        }
    }
    QLabel *q = new QLabel;
    q->resize(ImageAverage.width()/2,ImageAverage.height()/2);
    q->setPixmap(QPixmap::fromImage(ImageAverage));
    //自适应
    q->setScaledContents(1);
    q->show();
}

void w2::histMatch(QImage *image)
{
//    QImage *referenceImg;
//    referenceImg->load(fileNames[0]);
//    //new一个与image大小相等，值全为0的数组
//    int out[image->width()][image->height()];
//    memset(out,0,sizeof(out));
//    for(int i =0;i<3;i++){

//    }
}

w2::~w2()
{
    delete ui;
}

QImage w2::toGray(QImage *image)
{
    int height = image->height();
    int width = image->width();
    QImage ret(width, height, QImage::Format_Indexed8);
    ret.setColorCount(256);
    for(int i = 0; i < 256; i++)
    {
        ret.setColor(i, qRgb(i, i, i));
    }
    switch(image->format())
    {
    case QImage::Format_Indexed8:
        for(int i = 0; i < height; i ++)
        {
            const uchar *pSrc = (uchar *)image->constScanLine(i);
            uchar *pDest = (uchar *)ret.scanLine(i);
            memcpy(pDest, pSrc, width);
        }
        break;
    case QImage::Format_RGB32:
    case QImage::Format_ARGB32:
    case QImage::Format_ARGB32_Premultiplied:
        for(int i = 0; i < height; i ++)
        {
            const QRgb *pSrc = (QRgb *)image->constScanLine(i);
            uchar *pDest = (uchar *)ret.scanLine(i);

            for( int j = 0; j < width; j ++)
            {
                pDest[j] = qGray(pSrc[j]);
            }
        }
        break;
    }
    return ret;
}

//void w2::getPic(QImage *img)
//{
//    this->pic=img;
//    qDebug()<<"pic";
//    if(pic->isNull())
//        qDebug()<<"获取图片失败";
//}

//void w2::showHistogram(QImage *grayimage)
//{
//    //QImage *grayimage = new QImage();
//    *grayimage = toGray(grayimage);
//    //  对直方图进行数据处理,求出各个灰度值的像素数
//    int data[256]{0};
//    int yRange = 0;
//    int width = grayimage->width();
//    int height = grayimage->height();
//    for(int i = 0; i <width; i++){
//        for(int j = 0; j < height; j++){
//            int index = grayimage->pixelIndex(i, j);
//            ++data[index];
//        }
//    }

//    //设置每个“柱”的颜色，值，宽度等

//    QBarSet *set = new QBarSet("灰度值");
//    for (int i=0;i<256;i++) {
//        set->append(data[i]);
//        if(yRange<data[i]) yRange = data[i];
//        set->setColor(QColor::Rgb);
//    }
//    QBarSeries *series = new QBarSeries();
//    series->append(set);
//    series->setBarWidth(1.2);

//    //设置横坐标
//    QStringList categories;
//    for(int i=0; i<256; i++)
//        categories.push_back("");
//    QBarCategoryAxis *axisX = new QBarCategoryAxis();
//    axisX->append(categories);

//    //设置纵坐标
//    QValueAxis *axisY = new QValueAxis;
//    axisY->setLabelFormat("%d");
//    axisY->setRange(0,yRange);

//    //建表
//    QChart *chart = new QChart();
//    chart->addSeries(series);
//    chart->createDefaultAxes();
//    chart->setAxisX(axisX);
//    chart->setAxisY(axisY);
//    chart->setTitle("灰度直方图");
//    chart->setAnimationOptions(QChart::SeriesAnimations);
//    chart->legend()->setVisible(false);

//    //表的容器
//    QChartView *chartview = new QChartView(chart);
//    chartview->setChart(chart);
//    chartview->setRenderHint(QPainter::Antialiasing);
//    chartview->setVisible(true);
//    chartview->resize(800,500);
//    chartview->show();
//    qDebug()<<"showHistogram";
//}



void w2::on_ok_clicked()
{
    //qDebug()<<"on_ok_clicked";

        if(ui->comboBox_3->currentText()=="直方图均衡化")
        {
            //showHistogram(pic);
            //makePicAverage(pic);
            emit sendinfo("直方图均衡化",NULL);
        }
    else
        {
            if(ui->label->text()!=""){
                emit sendinfo("直方图匹配",ui->label->text());
            }
            else{QMessageBox::information(this, "提示", tr("请先选择图片！"),
                                     QMessageBox::Yes, QMessageBox::Yes);}
        }

}

void w2::on_pushButton_clicked()
{
    fileNames = QFileDialog::getOpenFileNames(this, tr("打开文件"),
                                                              "D:", tr("图片文件(*png *jpg)"));
        ui->label->setText(fileNames[0]);
}

void w2::on_comboBox_3_activated(const QString &arg1)
{

        if(arg1=="直方图匹配")
        {
            ppshow();
        }
        if(arg1=="直方图均衡化")
        {
            ppclose();
        }

}

void w2::on_pushButton_2_clicked()
{
    emit save(1);

QMessageBox::information(this, "提示", tr("操作已保存"),
                         QMessageBox::Yes, QMessageBox::Yes);
}

void w2::on_pushButton_3_clicked()
{
    emit save(2);
    QMessageBox::information(this, "提示", tr("重置完毕"),
                             QMessageBox::Yes, QMessageBox::Yes);
}

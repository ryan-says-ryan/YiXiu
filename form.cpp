#include "form.h"
#include "ui_form.h"
#include"funcs.h"
#include"appinfo.h"

form::form(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::form)
{
    ui->setupUi(this);
    welcomeWg = new w0(this);
    //    grayWg = new w1(this);
    //    histWg = new w2(this);
    //    smoothWg = new w3(this);
    //    sharpenWg = new w4(this);
    //    noiseWg = new w5_1(this);
    //    filterWg = new w6(this);
    //    rgbWg = new w7(this);


    //初始化当前界面和上一界面
    forml=welcomeWg;
    now=welcomeWg;
    welcomeWg->move(ui->widget_4->x(),ui->widget_4->y());
    welcomeWg->setGeometry(ui->widget_4->x(),ui->widget_4->y(),ui->widget_4->width(),ui->widget_4->height());
    welcomeWg->show();
    //加载按钮图标
    ui->noiseBtn->setCursor(Qt::PointingHandCursor);
    ui->noiseBtn->setStyleSheet("QPushButton{border-image:url(:/new/prefix1/image/noise1.png);}"
                                "QPushButton:hover{border-image:url(:/new/prefix1/image/noise2.png);}"
                                "QPushButton:pressed{border-image:url(:/new/prefix1/image/noise3.png);}");
    ui->histBtn->setCursor(Qt::PointingHandCursor);
    ui->histBtn->setStyleSheet("QPushButton{border-image:url(:/new/prefix1/image/hist1.png);}"
                               "QPushButton:hover{border-image:url(:/new/prefix1/image/hist2.png);}"
                               "QPushButton:pressed{border-image:url(:/new/prefix1/image/hist.png);}");
    ui->grayBtn->setCursor(Qt::PointingHandCursor);
    ui->grayBtn->setStyleSheet("QPushButton{border-image:url(:/new/prefix1/image/gray1.png);}"
                               "QPushButton:hover{border-image:url(:/new/prefix1/image/gray2.png);}"
                               "QPushButton:pressed{border-image:url(:/new/prefix1/image/gray3.png);}");
    ui->shapeBtn->setCursor(Qt::PointingHandCursor);
    ui->shapeBtn->setStyleSheet("QPushButton{border-image:url(:/new/prefix1/image/xz1.png);}"
                                "QPushButton:hover{border-image:url(:/new/prefix1/image/xz2.png);}"
                                "QPushButton:pressed{border-image:url(:/new/prefix1/image/xz3.png);}");
    ui->filterBtn->setCursor(Qt::PointingHandCursor);
    ui->filterBtn->setStyleSheet("QPushButton{border-image:url(:/new/prefix1/image/lvbo1.png);}"
                                 "QPushButton:hover{border-image:url(:/new/prefix1/image/lvbo2.png);}"
                                 "QPushButton:pressed{border-image:url(:/new/prefix1/image/lvbo3.png);}");
    ui->sharpenBtn->setCursor(Qt::PointingHandCursor);
    ui->sharpenBtn->setStyleSheet("QPushButton{border-image:url(:/new/prefix1/image/sharp1.png);}"
                                  "QPushButton:hover{border-image:url(:/new/prefix1/image/sharp2.png);}"
                                  "QPushButton:pressed{border-image:url(:/new/prefix1/image/sharp3.png);}");
    //    ui->pushButton_2->setCursor(Qt::PointingHandCursor);
    //    ui->pushButton_2->setStyleSheet("QPushButton{border-image:url(:/new/prefix1/image/gray1.png);}"
    //                                  "QPushButton:hover{border-image:url(:/new/prefix1/image/gray2.png);}"
    //                                  "QPushButton:pressed{border-image:url(:/new/prefix1/image/小.png);}");
    ui->smoothBtn->setCursor(Qt::PointingHandCursor);
    ui->smoothBtn->setStyleSheet("QPushButton{border-image:url(:/new/prefix1/image/smooth1.png);}"
                                 "QPushButton:hover{border-image:url(:/new/prefix1/image/smooth2.png);}"
                                 "QPushButton:pressed{border-image:url(:/new/prefix1/image/smooth3.png);}");
    ui->reduceBtn->setCursor(Qt::PointingHandCursor);
    ui->reduceBtn->setStyleSheet("QPushButton{border-image:url(:/new/prefix1/image/-1.png);}"
                                 "QPushButton:hover{border-image:url(:/new/prefix1/image/-2.png);}"
                                 "QPushButton:pressed{border-image:url(:/new/prefix1/image/-3.png);}");
    ui->enlargeBtn->setCursor(Qt::PointingHandCursor);
    ui->enlargeBtn->setStyleSheet("QPushButton{border-image:url(:/new/prefix1/image/+1.png);}"
                                  "QPushButton:hover{border-image:url(:/new/prefix1/image/+2.png);}"
                                  "QPushButton:pressed{border-image:url(:/new/prefix1/image/+3.png);}");
    ui->mirrorBtn->setCursor(Qt::PointingHandCursor);
    ui->mirrorBtn->setStyleSheet("QPushButton{border-image:url(:/new/prefix1/image/j1.png);}"
                                 "QPushButton:hover{border-image:url(:/new/prefix1/image/j2.png);}"
                                 "QPushButton:pressed{border-image:url(:/new/prefix1/image/j3.png);}");
    ui->cutBtn->setCursor(Qt::PointingHandCursor);
    ui->cutBtn->setStyleSheet("QPushButton{border-image:url(:/new/prefix1/image/cai1.png);}"
                              "QPushButton:hover{border-image:url(:/new/prefix1/image/cai2.png);}"
                              "QPushButton:pressed{border-image:url(:/new/prefix1/image/cai3.png);}");
    ui->preBtn->setCursor(Qt::PointingHandCursor);
    ui->preBtn->setStyleSheet("QPushButton{border-image:url(:/new/prefix1/image/left1.png);}"
                              "QPushButton:hover{border-image:url(:/new/prefix1/image/left2.png);}"
                              "QPushButton:pressed{border-image:url(:/new/prefix1/image/left3.png);}");

    ui->nextBtn->setCursor(Qt::PointingHandCursor);
    ui->nextBtn->setStyleSheet("QPushButton{border-image:url(:/new/prefix1/image/right1.png);}"
                               "QPushButton:hover{border-image:url(:/new/prefix1/image/right2.png);}"
                               "QPushButton:pressed{border-image:url(:/new/prefix1/image/right3.png);}");
    ui->spinBtn->setCursor(Qt::PointingHandCursor);
    ui->spinBtn->setStyleSheet("QPushButton{border-image:url(:/new/prefix1/image/rotate1.png);}"
                               "QPushButton:hover{border-image:url(:/new/prefix1/image/rotate2.png);}"
                               "QPushButton:pressed{border-image:url(:/new/prefix1/image/rotate3.png);}");

    //注册显示图片label的事件过滤器
    ui->label->installEventFilter(this);

}

form::~form()
{
    delete ui;
}

//接收处理w1信号
void form::W1processing(QString s1,QString s2,int yz,int c,double y)//参数分别为图像灰度化..（4种）,最大值法（3）,阈值，c，y，无则null。
{
    QImage newim;
    this->saved=0;
    qDebug()<<s1<<s2<<yz<<c<<y;
    if(s1=="图像灰度化")
    {
        if(s2=="最大值法")
        {
            newim=Togray_max(&this->originalim);
            this->displayim=newim;
            ui->label->setPixmap(QPixmap::fromImage(newim));
            QMessageBox::information(this, "提示", tr("处理完毕"),
                                     QMessageBox::Yes, QMessageBox::Yes);
        }
        if(s2=="平均值法")
        {
            newim=Togray_average(&this->originalim);
            this->displayim=newim;
            ui->label->setPixmap(QPixmap::fromImage(newim));
            QMessageBox::information(this, "提示", tr("处理完毕"),
                                     QMessageBox::Yes, QMessageBox::Yes);
        }
        if(s2=="加权平均法")
        {
            newim=Togray_weight(&this->originalim);
            this->displayim=newim;
            ui->label->setPixmap(QPixmap::fromImage(newim));
            QMessageBox::information(this, "提示", tr("处理完毕"),
                                     QMessageBox::Yes, QMessageBox::Yes);
        }

    }
    if(s1=="图像反转")
    {
        newim=fanzhuan(&this->originalim);
        this->displayim=newim;
        ui->label->setPixmap(QPixmap::fromImage(newim));
        QMessageBox::information(this, "提示", tr("处理完毕"),
                                 QMessageBox::Yes, QMessageBox::Yes);
    }
    if(s1=="图像二值化")
    {
        newim=erzhihua(&this->originalim,yz);
        this->displayim=newim;
        ui->label->setPixmap(QPixmap::fromImage(newim));
        QMessageBox::information(this, "提示", tr("处理完毕"),
                                 QMessageBox::Yes, QMessageBox::Yes);
    }
    if(s1=="幂律变换")
    {
        qDebug()<<c<<y;
        newim=milv(&this->originalim,c,y);
        this->displayim=newim;
        ui->label->setPixmap(QPixmap::fromImage(newim));
        QMessageBox::information(this, "提示", tr("处理完毕"),
                                 QMessageBox::Yes, QMessageBox::Yes);
    }

}
//接收处理w2信号
void form::W2processing(QString s1,QString s2)//类型，path
{
    QImage newim;
    this->saved=0;
    qDebug()<<s1<<s2;
    if(s1=="直方图均衡化")
    {
        newim=histavg(&this->originalim);
        this->displayim=newim;
        this->p1=&newim;
        ui->label->setPixmap(QPixmap::fromImage(this->displayim));
        QMessageBox::information(this, "提示", tr("处理完毕"),
                                 QMessageBox::Yes, QMessageBox::Yes);
    }
    if(s1=="直方图匹配")
    {
        QString filename=s2;
        QImage cmpimage;
        cmpimage.load(filename);
        newim=histmatch(&this->originalim,&cmpimage);
        this->displayim=newim;
        this->p1=&newim;
        ui->label->setPixmap(QPixmap::fromImage(this->displayim));
        QMessageBox::information(this, "提示", tr("处理完毕"),
                                 QMessageBox::Yes, QMessageBox::Yes);

    }
}
//接收处理w3信号
void form::W3processing(QString s1,int size,float sigma)//类型，size,sigma
{
    this->saved=0;
    QImage newim;
    qDebug()<<s1<<size<<sigma;

    if(s1=="均值滤波")
    {
        newim=jzlb(&this->originalim,size);
        this->displayim=newim;
        this->p1=&newim;
        ui->label->setPixmap(QPixmap::fromImage(this->displayim));
        QMessageBox::information(this, "提示", tr("处理完毕"),
                                 QMessageBox::Yes, QMessageBox::Yes);
    }
    if(s1=="中值滤波")
    {
        newim=zzlb(&this->originalim,size);
        this->displayim=newim;
        this->p1=&newim;
        ui->label->setPixmap(QPixmap::fromImage(this->displayim));
        QMessageBox::information(this, "提示", tr("处理完毕"),
                                 QMessageBox::Yes, QMessageBox::Yes);
    }


}
//接收处理w4信号
void form::W4processing(QString s1)//类型
{
    this->saved=0;
    qDebug()<<s1;
    QImage newim;
    if(s1=="sobel算子")
    {
        newim=sobel(&this->originalim);
        this->displayim=newim;
        this->p1=&newim;
        ui->label->setPixmap(QPixmap::fromImage(this->displayim));
        QMessageBox::information(this, "提示", tr("处理完毕"),
                                 QMessageBox::Yes, QMessageBox::Yes);
    }
    if(s1=="robert算子")
    {
        newim=robert(&this->originalim);
        this->displayim=newim;
        this->p1=&newim;
        ui->label->setPixmap(QPixmap::fromImage(this->displayim));
        QMessageBox::information(this, "提示", tr("处理完毕"),
                                 QMessageBox::Yes, QMessageBox::Yes);
    }
    if(s1=="prewitt算子")
    {
        newim=prewitt(&this->originalim);
        this->displayim=newim;
        this->p1=&newim;
        ui->label->setPixmap(QPixmap::fromImage(this->displayim));
        QMessageBox::information(this, "提示", tr("处理完毕"),
                                 QMessageBox::Yes, QMessageBox::Yes);
    }
    if(s1=="laplacian算子")
    {
        newim=laplacian(&this->originalim);
        this->displayim=newim;
        this->p1=&newim;
        ui->label->setPixmap(QPixmap::fromImage(this->displayim));
        QMessageBox::information(this, "提示", tr("处理完毕"),
                                 QMessageBox::Yes, QMessageBox::Yes);
    }
}
//接收处理w5信号
void form::W5processing(QString s1,float jz,float fc,int md)//类型,均值，方差，密度
{
    this->saved=0;
    qDebug()<<s1<<jz<<fc<<md;
}
//接收处理w6信号
void form::W6processing(QString s1,QString s2,int r,int n,int m)//类型,类型，半径r，阶数n，带宽w
{
    this->saved=0;
    qDebug()<<s1<<s2<<r<<n<<m;
}
//接收处理w7信号
void form::W7processing(QString s1,QString s2,QString s3,int sbd)//类型,类型，识别度
{
    this->saved=0;
    qDebug()<<s1<<s2<<s3<<sbd;
}
void form::W1save(int save)
{
    this->saved=save;
    if(save==1)//保存
    {
        this->originalim=this->displayim;
        ims.append(this->originalim);
        loc++;
    }
    if(save==2)//重置
    {
        this->displayim=this->originalim;
        ui->label->setPixmap(QPixmap::fromImage(this->displayim));
    }
}
void form::W2save(int save)
{
    this->saved=save;
    if(save==1)
    {
        this->originalim=this->displayim;
        ims.append(this->originalim);
        loc++;
    }
    if(save==2)
    {
        this->displayim=this->originalim;
        ui->label->setPixmap(QPixmap::fromImage(this->displayim));
    }
}
void form::W3save(int save)
{
    this->saved=save;
    if(save==1)
    {
        this->originalim=this->displayim;
        ims.append(this->originalim);
        loc++;
    }
    if(save==2)
    {
        this->displayim=this->originalim;
        ui->label->setPixmap(QPixmap::fromImage(this->displayim));
    }
}
void form::W4save(int save)
{
    this->saved=save;
    if(save==1)
    {
        this->originalim=this->displayim;
        ims.append(this->originalim);
        loc++;
    }
    if(save==2)
    {
        this->displayim=this->originalim;
        ui->label->setPixmap(QPixmap::fromImage(this->displayim));
    }
}
void form::W5save(int save)
{
    this->saved=save;
    if(save==1)
    {
        this->originalim=this->displayim;
        ims.append(this->originalim);
        loc++;
    }
    if(save==2)
    {
        this->displayim=this->originalim;
        ui->label->setPixmap(QPixmap::fromImage(this->displayim));
    }
}
void form::W6save(int save)
{

    this->saved=save;
    if(save==1)
    {
        this->originalim=this->displayim;
        ims.append(this->originalim);
        loc++;
    }
    if(save==2)
    {
        this->displayim=this->originalim;
        ui->label->setPixmap(QPixmap::fromImage(this->displayim));
    }

}
void form::W7save(int save)
{
    this->saved=save;
    if(save==1)
    {
        this->originalim=this->displayim;
        ims.append(this->originalim);
        loc++;
    }
    if(save==2)
    {
        this->displayim=this->originalim;
        ui->label->setPixmap(QPixmap::fromImage(this->displayim));
    }
}

//焦点在图片上时
bool form::eventFilter(QObject *obj, QMouseEvent *e)
{
    //    if(qobject_cast<QLabel*>(obj) == ui->label && e->type() == QMouseEvent::Move&&QMouseEvent::)
    //        {
    //            qDebug()<<"pos="<<e->pos();
    //            return true;
    //        }

    //        return false;
}

void form::mouseMoveEvent(QMouseEvent *event)
{
    if(mouseFlagX1){
        this->setCursor(Qt::SplitHCursor);
        QSize qsize = this->size();
        //qDebug().noquote()<<"Moving X:"<<event->x();
        int xChanged = event->x()-mousePosX;
        //        ui->scrollArea->resize(ui->scrollArea->geometry().width()+xChanged,ui->widget_4->geometry().height());
        ui->scrollArea->resize(ui->scrollArea->geometry().width()+xChanged,ui->widget_4->geometry().height());
        ui->widget_4->setGeometry(ui->widget_4->geometry().x()+xChanged,ui->widget_4->geometry().y(),ui->widget_4->geometry().width()-xChanged,ui->widget_4->geometry().height());
        if(now){
            now->setGeometry(ui->widget_4->geometry().x(),ui->widget_4->geometry().y(),ui->widget_4->geometry().width(),ui->widget_4->geometry().height());
        }//ui->label->resize(ui->label->width()+xChanged,ui->label->geometry().height()*int(((ui->label->width()+xChanged)/ui->label->width())));
        QRect a=ui->scrollArea->rect();

        qDebug()<<a.center()<<endl;
        ui->label->move(a.center().x()-ui->label->width()/2,a.center().y()-ui->label->height()/2);

        mousePosX = event->x();
    }
    if(abs(event->x()-ui->widget_4->x())<10){
        this->setCursor(Qt::SplitHCursor);
    }
}

void form::mousePressEvent(QMouseEvent *event)
{
    if(event->x()<=(ui->widget_2->geometry().width()+10) && event->x()>=(ui->widget_2->geometry().width()-10) )
    {
        this->setCursor(Qt::SplitHCursor);
        mousePosX = event->x();

        mouseFlagX = true;
        qDebug().noquote()<<"X";
    }

    if(event->x()<=(ui->widget_2->geometry().width()+ui->scrollArea->geometry().width()+10) && event->x()>=(ui->widget_2->geometry().width()+ui->scrollArea->geometry().width()-10))
    {
        this->setCursor(Qt::SplitHCursor);
        mousePosX = event->x();
        mouseFlagX1 = true;
        qDebug().noquote()<<"X1";
    }
}

void form::mouseReleaseEvent(QMouseEvent *event)
{
    this->setCursor(Qt::ArrowCursor);
    mouseFlagX = false;
    mouseFlagX1 = false;
    mouseFlagY = false;
    qDebug().noquote()<<event->x();
}

void form::resizeEvent(QResizeEvent *event)
{
    QSize qsize = this->size();
    ui->widget->resize(qsize.width(),ui->widget->height());
    ui->widget_2->resize(ui->widget_2->width(),qsize.height()-ui->widget->height()-2);
    ui->scrollArea->resize(qsize.width() - ui->widget_2->width()+2-ui->widget_4->width(),qsize.height()-ui->widget->height()-2);
    ui->widget_4->setGeometry(qsize.width()-ui->widget_4->width(),ui->widget->height(),ui->widget_4->width(),qsize.height()-ui->widget->height()-2);
    int x=ui->widget_4->x()-ui->scrollArea->width()/2-ui->label->width();
    int y=qsize.height()-ui->scrollArea->height()/2-ui->label->height();
    if(now){
        now->setGeometry(ui->widget_4->geometry().x(),ui->widget_4->geometry().y(),ui->widget_4->geometry().width(),ui->widget_4->geometry().height());
    }
    QRect a=ui->scrollArea->rect();

    qDebug()<<a.center()<<endl;
    ui->label->move(a.center().x()-ui->label->width()/2,a.center().y()-ui->label->height()/2);
}

void form::on_openFile_triggered()
{
    fileNames = QFileDialog::getOpenFileNames(this, tr("打开文件"),
                                              "D:", tr("图片文件(*png *jpg)"));
    if(!fileNames.isEmpty()){
        ims.clear();
        qDebug()<< "fileNames:" <<fileNames[0];
        p1->load(fileNames[0]);
        this->originalim=*p1;
        ims.append(this->originalim);
        this->displayim=*p1;
        const QString message = tr("Opened \"%1\", %2x%3, Depth: %4")
                .arg(QDir::toNativeSeparators(fileNames[0])).arg(p1->width()).arg(p1->height()).arg(p1->depth());
        statusBar()->showMessage(message);
        float width = p1->width();
        float height = p1->height();
        qDebug()<<p1->width();
        qDebug()<<p1->height();
        //重置图片尺寸，宽670，高730
        if(width>670.0){
            height = 670.0/width*height;
            width = 670;
        }
        if(height>730.0){
            width = 730.0/height*width;
            height=730;
        }
        //        ui->label->resize(p1->width()/2,p1->height()/2);
        ui->label->resize(width,height);
        QRect a=ui->scrollArea->rect();
        qDebug()<<a.center()<<endl;
        ui->label->move(a.center().x()-ui->label->width()/2,a.center().y()-ui->label->height()/2);
        qDebug()<<ui->label->size();
        ui->label->setPixmap(QPixmap::fromImage(p1->scaled(ui->label->size())));
        QMatrix matrix;
        matrix.rotate(360);
        ui->label->setPixmap(QPixmap::fromImage(*p1).transformed(matrix, Qt::SmoothTransformation));
        ui->label->setScaledContents(true);
    }
}

void form::on_preBtn_clicked()
{
    qDebug()<<"向前一步，未实现";
    if(loc>0){
        ui->label->setPixmap(QPixmap::fromImage(ims[--loc]));this->originalim=ims[loc];}
    else {
        QMessageBox::information(this, "提示", tr("已经是第一张了"),
                                 QMessageBox::Yes, QMessageBox::Yes);
    }
}

void form::on_nextBtn_clicked()
{
    qDebug()<<"向后一部";
    if(loc<ims.length()-1){
        ui->label->setPixmap(QPixmap::fromImage(ims[++loc]));
        this->originalim=ims[loc];}
    else {
        QMessageBox::information(this, "提示", tr("已经是最后一张了"),
                                 QMessageBox::Yes, QMessageBox::Yes);
    }
}

void form::on_enlargeBtn_clicked()
{
    ui->label->resize(ui->label->width()*1.1,ui->label->height()*1.1);
    QRect a=ui->scrollArea->rect();
    ui->label->move(a.center().x()-ui->label->width()/2,a.center().y()-ui->label->height()/2);
}

void form::on_reduceBtn_clicked()
{
    ui->label->resize(ui->label->width()*0.9,ui->label->height()*0.9);
    QRect a=ui->scrollArea->rect();
    ui->label->move(a.center().x()-ui->label->width()/2,a.center().y()-ui->label->height()/2);
}

//旋转
void form::on_spinBtn_clicked()
{
    int w=ui->label->width();
    int h=ui->label->height();
    int angle;
    switch (status) {
    case 0:
        angle=90;status++;break;
    case 1:
        angle=180;status++;break;
    case 2:
        angle=270;status++;break;
    case 3:
        angle=360;status++;break;
    }

    QMatrix matrix;
    matrix.rotate(angle);
    ui->label->resize(h,w);
    ui->label->setPixmap(QPixmap::fromImage(this->displayim).transformed(matrix, Qt::FastTransformation));
    QRect a=ui->scrollArea->rect();
    ui->label->move(a.center().x()-ui->label->width()/2,a.center().y()-ui->label->height()/2);
    qDebug()<<"spin";
    if(status==4)
        status=0;
}

void form::on_mirrorBtn_clicked()
{
    qDebug()<<"水平镜像";
    this->displayim = this->displayim.mirrored(true, false);
    ui->label->setPixmap(QPixmap::fromImage(this->displayim));
}

void form::on_cutBtn_clicked()
{
    qDebug()<<"裁剪，未实现";
    QMessageBox::information(this, "提示", tr("未实现"),
                             QMessageBox::Yes, QMessageBox::Yes);
}
//灰度处理
void form::on_grayBtn_clicked()
{
    if(saved){
        grayWg = new w1(this);
        connect(grayWg,&w1::sendinfo,this,&form::W1processing);
        connect(grayWg,&w1::save,this,&form::W1save);
        forml=now;
        now->close();
        now=grayWg;
        grayWg->move(ui->widget_4->x(),ui->widget_4->y());
        grayWg->setGeometry(ui->widget_4->x(),ui->widget_4->y(),ui->widget_4->width(),ui->widget_4->height());
        //点击左侧直方图图标时发送信号
        if(!this->displayim.isNull()){
            //emit sendPic(p1);
            qDebug()<<"show w1";
            grayWg->show();
        }
        else{
            QMessageBox::information(this, "提示", tr("请先打开一张图片！"),
                                     QMessageBox::Yes, QMessageBox::Yes);
        }
    }

    else {
        QMessageBox::information(this, "提示", tr("请先保存操作"),
                                 QMessageBox::Yes, QMessageBox::Yes);
    }
}

//直方图
void form::on_histBtn_clicked()
{
    if(saved){
        histWg = new w2(this);
        //与new出来的对象建立连接
        connect(histWg,&w2::sendinfo,this,&form::W2processing);
        //connect(this,&form::sendPic,histWg,&w2::setThisPic);
        connect(histWg,&w2::save,this,&form::W2save);
        forml=now;
        now->close();
        now=histWg;
        histWg->move(ui->widget_4->x(),ui->widget_4->y());
        histWg->setGeometry(ui->widget_4->x(),ui->widget_4->y(),ui->widget_4->width(),ui->widget_4->height());
        //点击左侧直方图图标时发送信号
        if(!this->displayim.isNull()){
            //emit sendPic(p1);
            qDebug()<<"发送成功";
            histWg->show();
        }
        else{
            QMessageBox::information(this, "提示", tr("请先打开一张图片！"),
                                     QMessageBox::Yes, QMessageBox::Yes);
        }
    }

    else {
        QMessageBox::information(this, "提示", tr("请先保存操作"),
                                 QMessageBox::Yes, QMessageBox::Yes);
    }
}

void form::on_smoothBtn_clicked()
{
    if(saved){
        smoothWg=new w3(this);
        connect(smoothWg,&w3::sendinfo,this,&form::W3processing);
        connect(smoothWg,&w3::save,this,&form::W3save);
        forml=now;
        now->close();
        now=smoothWg;
        smoothWg->move(ui->widget_4->x(),ui->widget_4->y());
        smoothWg->setGeometry(ui->widget_4->x(),ui->widget_4->y(),ui->widget_4->width(),ui->widget_4->height());
        if(!this->displayim.isNull()){
            //emit sendPic(p1);
            qDebug()<<"show w3";
            smoothWg->show();
        }
        else{
            QMessageBox::information(this, "提示", tr("请先打开一张图片！"),
                                     QMessageBox::Yes, QMessageBox::Yes);
        }
    }
    else {
        QMessageBox::information(this, "提示", tr("请先保存操作"),
                                 QMessageBox::Yes, QMessageBox::Yes);
    }
}

void form::on_sharpenBtn_clicked()
{
    if(saved){
        sharpenWg=new w4(this);
        connect(sharpenWg,&w4::sendinfo,this,&form::W4processing);
        connect(sharpenWg,&w4::save,this,&form::W4save);
        forml=now;
        now->close();
        now=sharpenWg;
        sharpenWg->move(ui->widget_4->x(),ui->widget_4->y());
        sharpenWg->setGeometry(ui->widget_4->x(),ui->widget_4->y(),ui->widget_4->width(),ui->widget_4->height());
        if(!this->displayim.isNull()){
            //emit sendPic(p1);
            qDebug()<<"show w4";
            sharpenWg->show();
        }
        else{
            QMessageBox::information(this, "提示", tr("请先打开一张图片！"),
                                     QMessageBox::Yes, QMessageBox::Yes);
        }
    }
    else {
        QMessageBox::information(this, "提示", tr("请先保存操作"),
                                 QMessageBox::Yes, QMessageBox::Yes);
    }

}

void form::on_noiseBtn_clicked()
{
    if(saved){
        noiseWg=new w5_1(this);
        connect(noiseWg,&w5_1::sendinfo,this,&form::W5processing);
        connect(noiseWg,&w5_1::save,this,&form::W5save);
        forml=now;
        now->close();
        now=noiseWg;
        noiseWg->move(ui->widget_4->x(),ui->widget_4->y());
        noiseWg->setGeometry(ui->widget_4->x(),ui->widget_4->y(),ui->widget_4->width(),ui->widget_4->height());
        if(!this->displayim.isNull()){
            //emit sendPic(p1);
            qDebug()<<"show w5";
            noiseWg->show();
        }
        else{
            QMessageBox::information(this, "提示", tr("请先打开一张图片！"),
                                     QMessageBox::Yes, QMessageBox::Yes);
        }
    }
    else {
        QMessageBox::information(this, "提示", tr("请先保存操作"),
                                 QMessageBox::Yes, QMessageBox::Yes);
    }
}

void form::on_filterBtn_clicked()
{
    if(saved){
        filterWg=new w6(this);
        connect(filterWg,&w6::sendinfo,this,&form::W6processing);
        connect(filterWg,&w6::save,this,&form::W6save);
        forml=now;
        now->close();
        now=filterWg;
        filterWg->move(ui->widget_4->x(),ui->widget_4->y());
        filterWg->setGeometry(ui->widget_4->x(),ui->widget_4->y(),ui->widget_4->width(),ui->widget_4->height());
        if(!this->displayim.isNull()){
            //emit sendPic(p1);
            qDebug()<<"show w6";
            filterWg->show();
        }
        else{
            QMessageBox::information(this, "提示", tr("请先打开一张图片！"),
                                     QMessageBox::Yes, QMessageBox::Yes);
        }
    }
    else {
        QMessageBox::information(this, "提示", tr("请先保存操作"),
                                 QMessageBox::Yes, QMessageBox::Yes);
    }
}

void form::on_shapeBtn_clicked()
{
    if(saved){
        shapeWg=new w7(this);
        connect(shapeWg,&w7::sendinfo,this,&form::W7processing);
        connect(shapeWg,&w7::save,this,&form::W7save);
        forml=now;
        now->close();
        now=shapeWg;
        shapeWg->move(ui->widget_4->x(),ui->widget_4->y());
        shapeWg->setGeometry(ui->widget_4->x(),ui->widget_4->y(),ui->widget_4->width(),ui->widget_4->height());
        if(!this->displayim.isNull()){
            //emit sendPic(p1);
            qDebug()<<"show w7";
            shapeWg->show();
        }
        else{
            QMessageBox::information(this, "提示", tr("请先打开一张图片！"),
                                     QMessageBox::Yes, QMessageBox::Yes);
        }
    }
    else {
        QMessageBox::information(this, "提示", tr("请先保存操作"),
                                 QMessageBox::Yes, QMessageBox::Yes);
    }
}
//保存图片
void form::on_actiona_triggered()
{
    QString filename1 = QFileDialog::getSaveFileName(this,tr("Save Image"),"",tr("Images (*.png *.bmp *.jpg)")); //选择路径
    QScreen *screen = QGuiApplication::primaryScreen();
    screen->grabWindow(ui->label->winId()).save(filename1);
    QMessageBox::information(this, "提示", tr("图片已保存"),
                             QMessageBox::Yes, QMessageBox::Yes);

}

void form::on_actionabout_triggered()
{
    appinfo *a=new appinfo(this);
    a->show();
}

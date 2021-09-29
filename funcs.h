#ifndef FUNCS_H
#define FUNCS_H
#include<QImage>
#include<QColor>
#include"qimage.h"
#include<algorithm>
#include<math.h>
#include<vector>
#include<QDebug>
#include<cmath>
using namespace std;
//part1 灰度处理

//1.图像灰度化
//1.1加权平均法
//QImage的图像不管怎么样都是三通道的图像数据
QImage Togray_weight(QImage *image)
{
    QImage newim;
    newim=QImage(image->width(),image->height(),image->format());
    for(int i=0;i<image->width();i++)
    {
        for(int j=0;j<image->height();j++)
        {
            QColor clr=image->pixel(i,j);
            int gray=0.3*clr.red()+0.59*clr.green()+0.11*clr.blue();
            newim.setPixelColor(i,j,qRgb(gray,gray,gray));
        }
    }
    return newim;
}
//1.2最大值法
QImage Togray_max(QImage *image)
{
    QImage newim;
    newim=QImage(image->width(),image->height(),image->format());
    for(int i=0;i<image->width();i++)
    {
        for(int j=0;j<image->height();j++)
        {
            QColor clr=image->pixel(i,j);
            int gray=max(max(clr.red(),clr.green()),clr.blue());
            newim.setPixelColor(i,j,qRgb(gray,gray,gray));
        }
    }
    return newim;
}

//1.3平均值法
QImage Togray_average(QImage *image)
{
    QImage newim;
    newim=QImage(image->width(),image->height(),image->format());
    for(int i=0;i<image->width();i++)
    {
        for(int j=0;j<image->height();j++)
        {
            QColor clr=image->pixel(i,j);
            int gray=0.33*clr.red()+0.33*clr.green()+0.33*clr.blue();
            newim.setPixelColor(i,j,qRgb(gray,gray,gray));
        }
    }
    return newim;
}

//2.图像反转 0
QImage fanzhuan(QImage *image)
{
    QImage newim;
    newim=QImage(image->width(),image->height(),image->format());
    for(int i=0;i<image->width();i++)
    {
        for(int j=0;j<image->height();j++)
        {
            QColor clr=image->pixel(i,j);
            int gray=255-clr.red();//g,b皆可
            newim.setPixelColor(i,j,qRgb(gray,gray,gray));
        }
    }
    return newim;
}
//3.图像二值化 1
QImage erzhihua(QImage *image,int n)
{
    QImage newim;
    newim=QImage(image->width(),image->height(),image->format());
    for(int i=0;i<image->width();i++)
    {
        for(int j=0;j<image->height();j++)
        {
            QColor clr=image->pixel(i,j);
            int gray=clr.red();//g,b皆可

            if(gray<n)
            {
                gray=0;
            }
            else {
                gray=255;
            }
            newim.setPixelColor(i,j,qRgb(gray,gray,gray));
        }
    }
    return newim;
}
//4.幂律变换  2
QImage milv(QImage *image,int c,double y)
{
    QImage newim;
    newim=QImage(image->width(),image->height(),image->format());

    for(int i=0;i<image->width();i++)
    {
        for(int j=0;j<image->height();j++)
        {
            QColor clr=image->pixel(i,j);
            int gray=c*int(pow(clr.red(),y));
            newim.setPixelColor(i,j,qRgb(gray,gray,gray));
        }

    }
    return newim;
}

//part2 直方图处理

//1.直方图均衡 0
QImage histavg(QImage *image)
{
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
    return ImageAverage;
}
//2.直方图匹配 1
QImage histmatch(QImage *image1,QImage *image2)
{
    QImage origin;
    QImage match;
    QImage outim;
    outim=QImage(image1->width(),image1->height(),image1->format());
    int i,j;
    int width,height,m_width,m_height;
    width=image1->width();
    height=image1->height();
    m_width=image2->width();
    m_height=image2->height();
    QRgb rgb;
    float min;
    int index;
    int t;
    int matcharray[256];
    int r[256],g[256],b[256];//原图各个灰度数量的统计
    int mr[256],mg[256],mb[256];//参考图各个灰度数量的统计

    float rPro[256],gPro[256],bPro[256];//原图各个灰度级的概率
    float mrPro[256],mgPro[256],mbPro[256];//参考图各个灰度级的概率

    //获取原图各个灰度的数量
    for(i=0;i<width;i++)
    {
        for(j=0;j<height;j++)
        {
            rgb=image1->pixel(i,j);
            r[qRed(rgb)]++;
            g[qGreen(rgb)]++;
            b[qBlue(rgb)]++;

        }
    }
    //获取参考图各个灰度的数量
    for(i=0;i<m_width;i++)
    {
        for(j=0;j<m_height;j++)
        {
            rgb=image2->pixel(i,j);
            mr[qRed(rgb)]++;
            mg[qGreen(rgb)]++;
            mb[qBlue(rgb)]++;

        }
    }

    //获取各个灰度级的概率
    for(i=0;i<256;i++)
    {
        rPro[i]=(r[i]*1.0)/(width*height);
        gPro[i]=(g[i]*1.0)/(width*height);
        bPro[i]=(b[i]*1.0)/(width*height);
        mrPro[i]=(mr[i]*1.0)/(m_width*m_height);
        mgPro[i]=(mg[i]*1.0)/(m_width*m_height);
        mbPro[i]=(mb[i]*1.0)/(m_width*m_height);
    }
    //r
    for (i=0;i<256;i++)
    {
        float a=rPro[i];
        min = 1;
        index=1;
        for (j=0;j<256;j++)
        {
            float b = mrPro[j];
            if (abs(a-b)<min)
            {
                min=abs(a-b);
                index=j;
            }
        }
        matcharray[i]=index-1;
    }
    for (i=0;i<width;i++)
    {
         for (j=0;j<height;j++)
         {
             QColor clr=image1->pixel(i,j);
             t=clr.red();
             outim.setPixelColor(i,j,qRed(matcharray[t+1]));
         }
    }
    //g
    for (i=0;i<256;i++)
    {
        float a=gPro[i];
        min = 1;
        index=1;
        for (j=0;j<256;j++)
        {
            float b = mrPro[j];
            if (abs(a-b)<min)
            {
                min=abs(a-b);
                index=j;
            }
        }
        matcharray[i]=index-1;
    }
    for (i=0;i<width;i++)
    {
         for (j=0;j<height;j++)
         {
             QColor clr=image1->pixel(i,j);
             t=clr.green();
             outim.setPixelColor(i,j,qGreen(matcharray[t+1]));
         }
    }
    //b
    for (i=0;i<256;i++)
    {
        float a=bPro[i];
        min = 1;
        index=1;
        for (j=0;j<256;j++)
        {
            float b = mrPro[j];
            if (abs(a-b)<min)
            {
                min=abs(a-b);
                index=j;
            }
        }
        matcharray[i]=index-1;
    }
    for (i=0;i<width;i++)
    {
         for (j=0;j<height;j++)
         {
             QColor clr=image1->pixel(i,j);
             t=clr.blue();
             outim.setPixelColor(i,j,qBlue(matcharray[t+1]));
         }
    }

    return outim;

}

//part3 平滑处理

//1.均值滤波 1
QImage jzlb(QImage *image,int size)
{
    QImage newim;
    newim=QImage(image->width(),image->height(),image->format());
    int r=0,g=0,b=0;
    vector<QColor>clr;
    clr.resize(25);
    if(size==3)
    {
        for(int i=1;i<image->width()-1;i++)
        {
            for(int j=1;j<image->height()-1;j++)
            {
                clr[0]=image->pixel(i-1,j-1);clr[1]=image->pixel(i-1,j);clr[2]=image->pixel(i-1,j+1);
                clr[3]=image->pixel(i,j-1);clr[4]=image->pixel(i,j);clr[5]=image->pixel(i,j+1);
                clr[6]=image->pixel(i+1,j-1);clr[7]=image->pixel(i+1,j);clr[8]=image->pixel(i+1,j+1);
                for(int n=0;n<9;n++)
                {
                    r+=clr[n].red();
                    g+=clr[n].green();
                    b+=clr[n].blue();
                }
                r=r/9;
                g=g/9;
                b=b/9;
                newim.setPixelColor(i,j,qRgb(r,g,b));
            }
        }

    }
    else if (size==5) {
        for(int i=2;i<image->width()-2;i++)
        {
            for(int j=2;j<image->height()-2;j++)
            {
                clr[0]=image->pixel(i-2,j-2);clr[1]=image->pixel(i-2,j-1);clr[2]=image->pixel(i-2,j);clr[3]=image->pixel(i-2,j+1);clr[4]=image->pixel(i-2,j+2);
                clr[5]=image->pixel(i-1,j-2);clr[6]=image->pixel(i-1,j-1);clr[7]=image->pixel(i-1,j);clr[8]=image->pixel(i-1,j+1);clr[9]=image->pixel(i-1,j+2);
                clr[10]=image->pixel(i,j-2);clr[11]=image->pixel(i,j-1);clr[12]=image->pixel(i,j);clr[13]=image->pixel(i,j+1);clr[14]=image->pixel(i,j+2);
                clr[15]=image->pixel(i+1,j-2);clr[16]=image->pixel(i+1,j-1);clr[17]=image->pixel(i+1,j);clr[18]=image->pixel(i+1,j+1);clr[19]=image->pixel(i+1,j+2);
                clr[20]=image->pixel(i+2,j-2);clr[21]=image->pixel(i+2,j-1);clr[22]=image->pixel(i+2,j);clr[23]=image->pixel(i+2,j+1);clr[24]=image->pixel(i+2,j+2);
                for(int n=0;n<25;n++)
                {
                    r+=clr[n].red();
                    g+=clr[n].green();
                    b+=clr[n].blue();
                }
                r=r/25;
                g=g/25;
                b=b/25;
                newim.setPixelColor(i,j,qRgb(r,g,b));
            }
        }
    }

    return newim;
}
//2.中值滤波 1
QImage zzlb(QImage *image,int size)
{
    QImage newim;
    newim=QImage(image->width(),image->height(),image->format());
    int r=0,g=0,b=0;
    vector<QColor>clr;
    clr.resize(25);
    vector<int>r1,g1,b1;
    r1.resize(25);
    r1[4]=0;
    g1.resize(25);
    g1[4]=0;
    b1.resize(25);
    b1[4]=0;
    if(size==3)
    {
        for(int i=1;i<image->width()-1;i++)
        {
            for(int j=1;j<image->height()-1;j++)
            {
                clr[0]=image->pixel(i-1,j-1);clr[1]=image->pixel(i-1,j);clr[2]=image->pixel(i-1,j+1);
                clr[3]=image->pixel(i,j-1);clr[4]=image->pixel(i,j);clr[5]=image->pixel(i,j+1);
                clr[6]=image->pixel(i+1,j-1);clr[7]=image->pixel(i+1,j);clr[8]=image->pixel(i+1,j+1);
                for(int n=0;n<9;n++)
                {
                    r1[n]=clr[n].red();
                    g1[n]=clr[n].green();
                    b1[n]=clr[n].blue();
                }
                sort(r1.begin(),r1.begin()+9);
                sort(g1.begin(),g1.begin()+9);
                sort(b1.begin(),b1.begin()+9);
                r=r1[4];
                g=g1[4];
                b=b1[4];
                newim.setPixelColor(i,j,qRgb(r,g,b));
            }
        }

    }
    else if (size==5) {
        for(int i=2;i<image->width()-2;i++)
        {
            for(int j=2;j<image->height()-2;j++)
            {
                clr[0]=image->pixel(i-2,j-2);clr[1]=image->pixel(i-2,j-1);clr[2]=image->pixel(i-2,j);clr[3]=image->pixel(i-2,j+1);clr[4]=image->pixel(i-2,j+2);
                clr[5]=image->pixel(i-1,j-2);clr[6]=image->pixel(i-1,j-1);clr[7]=image->pixel(i-1,j);clr[8]=image->pixel(i-1,j+1);clr[9]=image->pixel(i-1,j+2);
                clr[10]=image->pixel(i,j-2);clr[11]=image->pixel(i,j-1);clr[12]=image->pixel(i,j);clr[13]=image->pixel(i,j+1);clr[14]=image->pixel(i,j+2);
                clr[15]=image->pixel(i+1,j-2);clr[16]=image->pixel(i+1,j-1);clr[17]=image->pixel(i+1,j);clr[18]=image->pixel(i+1,j+1);clr[19]=image->pixel(i+1,j+2);
                clr[20]=image->pixel(i+2,j-2);clr[21]=image->pixel(i+2,j-1);clr[22]=image->pixel(i+2,j);clr[23]=image->pixel(i+2,j+1);clr[24]=image->pixel(i+2,j+2);
                for(int n=0;n<25;n++)
                {
                    r1[n]=clr[n].red();
                    g1[n]=clr[n].green();
                    b1[n]=clr[n].blue();
                }
                sort(r1.begin(),r1.begin()+25);
                sort(g1.begin(),g1.begin()+25);
                sort(b1.begin(),b1.begin()+25);
                r=r1[12];
                g=g1[12];
                b=b1[12];
                newim.setPixelColor(i,j,qRgb(r,g,b));
            }
        }
    }
    return newim;
}
//3.高斯滤波 2参
void generateGaussianTemplate(double window[][11], int ksize, double sigma){
    int center = ksize / 2; //模板的中心位置，也就是坐标原点
    double PI=3.14;
    double x2, y2;
    for(int i = 0; i < ksize; i++){
        x2 = pow(i - center, 2);
        for(int j = 0; j < ksize; j++){
            y2 = pow(j - center, 2);
            double g = exp(-(x2 + y2)) / (2 * sigma * sigma);
            g /= 2 * PI * sigma;
            window[i][j] = g;
        }
    }
    //归一化左上角的数为1
    double k = 1 / window[0][0];
    for(int i = 0; i < ksize; i++) {
        for (int j = 0; j < ksize; j++) {
            window[i][j] *= k;
        }
    }
}


QImage gslb(QImage *image,double sigma)
{

//       QImage newImage;
//       newImage= QImage(image->width(),image->height(),QImage::Format_ARGB32);
//       double kernel [3][3] ;
//       generateGaussianTemplate(kernel, 3,  sigma);
//       int sizeKernel = 3;
//       int sumKernel = 16;
//       QColor color;
//        for(int x = sizeKernel/2;x<image->width() - sizeKernel/2;x++)
//       {
//          for(int y= sizeKernel/2;y<image->height() - sizeKernel/2;y++)
//           {
//               int r = 0;
//               int g = 0;
//               int b = 0;
//               for(int i = -sizeKernel/2;i<=sizeKernel/2;i++)
//               {
//                  for(int j = -sizeKernel/2;j<=sizeKernel/2;j++)
//                   {
//                    color = QColor(image->pixel(x+i,y+j));
//                    r+=color.red()*kernel[sizeKernel/2+i][sizeKernel/2+j];
//                    g+=color.green()*kernel[sizeKernel/2+i][sizeKernel/2+j];
//                    b+=color.blue()*kernel[sizeKernel/2+i][sizeKernel/2+j];
//                   }
//               }
//               r = qBound(0,r/sumKernel,255);
//               g = qBound(0,g/sumKernel,255);
//               b = qBound(0,b/sumKernel,255);
//               newImage.setPixel(x,y,qRgb( r,g,b));
//           }
//       }
//       return newImage;


}

//part4 锐化处理 参数只有image

int LimitValue(int val)
{
    if (val < 0)
        val = 0;
    else if (val > 255)
        val = 255;

    return val;
}
//1.sobel
QImage sobel(QImage *image)
{
    QImage newim;
    newim=QImage(image->width(),image->height(),image->format());
    vector<QColor>clr;
    clr.resize(9);
    for (int i = 1; i < image->height() - 1; i++)
        {
            for (int j = 1; j < image->width() - 1; j++)
            {
                clr[0]=image->pixel(i-1,j-1);clr[1]=image->pixel(i-1,j);clr[2]=image->pixel(i-1,j+1);
                clr[3]=image->pixel(i,j-1);clr[4]=image->pixel(i,j);clr[5]=image->pixel(i,j+1);
                clr[6]=image->pixel(i+1,j-1);clr[7]=image->pixel(i+1,j);clr[8]=image->pixel(i+1,j+1);

                //化简后结果   这里使用了 1,1.414,1 的模板（各向同性Sobel算子），与 1,2,1的模板区别不是很大
                float GXr =  clr[2].red() - clr[0].red() + (clr[5].red() - clr[3].red()) * 1.414 + clr[8].red() - clr[6].red();
                float GYr = clr[0].red() + clr[2].red() + (clr[1].red() - clr[7].red()) * 1.414 - clr[6].red() - clr[8].red();
                float GXg =  clr[2].green() - clr[0].green() + (clr[5].green() - clr[3].green()) * 1.414 + clr[8].green() - clr[6].green();
                float GYg = clr[0].green() + clr[2].green() + (clr[1].green() - clr[7].green()) * 1.414 - clr[6].green() - clr[8].green();
                float GXb =  clr[2].blue() - clr[0].blue() + (clr[5].blue() - clr[3].blue()) * 1.414 + clr[8].blue() - clr[6].blue();
                float GYb = clr[0].blue() + clr[2].blue() + (clr[1].blue() - clr[7].blue()) * 1.414 - clr[6].blue()- clr[8].blue();
                int valr = LimitValue(sqrt(GXr*GXr + GYr*GYr) + 0.5);
                int valg = LimitValue(sqrt(GXg*GXg + GYg*GYg) + 0.5);
                int valb = LimitValue(sqrt(GXb*GXb + GYb*GYb) + 0.5);
                newim.setPixelColor(i,j,qRgb(valr,valg,valb));
            }
        }
    return newim;

}
//2.robert
QImage robert(QImage *image)
{
    QImage newim;
    newim=QImage(image->width(),image->height(),image->format());
    vector<QColor>clr;
    clr.resize(4);
    for (int i = 1; i < image->height() - 1; i++)
        {
            for (int j = 1; j < image->width() - 1; j++)
            {
                clr[0]=image->pixel(i,j);clr[1]=image->pixel(i,j+1);clr[2]=image->pixel(i+1,j);
                clr[3]=image->pixel(i+1,j+1);

                int valr =LimitValue(sqrt(double ( (clr[0].red() - clr[3].red()) * (clr[0].red() - clr[3].red())+(clr[1].red() - clr[2].red()) * (clr[1].red() - clr[2].red()) ) ) + 0.5);
                int valg =LimitValue(sqrt(double ( (clr[0].green() - clr[3].green()) * (clr[0].green() - clr[3].green())+(clr[1].green() - clr[2].green()) * (clr[1].green() - clr[2].green()) ) ) + 0.5);
                int valb =LimitValue(sqrt(double ( (clr[0].blue() - clr[3].blue() ) * (clr[0].blue()  - clr[3].blue() )+(clr[1].blue()  - clr[2].blue() ) * (clr[1].blue()  - clr[2].blue() ) ) ) + 0.5);
                newim.setPixelColor(i,j,qRgb(valr,valg,valb));
            }
        }
    return newim;
}

//3.prewitt
QImage prewitt(QImage *image)
{
    //[111000-1-1-1],[-101*3]
    QImage newim;
    newim=QImage(image->width(),image->height(),image->format());
    vector<QColor>clr;
    clr.resize(9);
    for (int i = 1; i < image->height() - 1; i++)
        {
            for (int j = 1; j < image->width() - 1; j++)
            {
                clr[0]=image->pixel(i-1,j-1);clr[1]=image->pixel(i-1,j);clr[2]=image->pixel(i-1,j+1);
                clr[3]=image->pixel(i,j-1);clr[4]=image->pixel(i,j);clr[5]=image->pixel(i,j+1);
                clr[6]=image->pixel(i+1,j-1);clr[7]=image->pixel(i+1,j);clr[8]=image->pixel(i+1,j+1);

                //化简后结果   这里使用了 1,1.414,1 的模板（各向同性Sobel算子），与 1,2,1的模板区别不是很大
                float GXr =  clr[0].red() + clr[1].red() + clr[2].red() - clr[6].red() - clr[7].red() - clr[8].red();
                float GYr = clr[2].red() + clr[5].red() + clr[8].red() - clr[0].red() - clr[3].red() - clr[6].red();
                float GXg =  clr[0].green() + clr[1].green() + clr[2].green() - clr[6].green() - clr[7].green() - clr[8].green();
                float GYg = clr[2].green() + clr[5].green()+ clr[8].green() - clr[0].green() - clr[3].green() - clr[6].green();
                float GXb =  clr[0].blue() + clr[1].blue() + clr[2].blue()- clr[6].blue() - clr[7].blue() - clr[8].blue();
                float GYb = clr[2].blue() + clr[5].blue() + clr[8].blue() - clr[0].blue() - clr[3].blue() - clr[6].blue();
                int valr = LimitValue(sqrt(GXr*GXr + GYr*GYr) + 0.5);
                int valg = LimitValue(sqrt(GXg*GXg + GYg*GYg) + 0.5);
                int valb = LimitValue(sqrt(GXb*GXb + GYb*GYb) + 0.5);
                newim.setPixelColor(i,j,qRgb(valr,valg,valb));
            }
        }
    return newim;
}

//4.laplacian
QImage laplacian(QImage *image)
{
    //int Template3[3][3] = { 0, -1, 0, -1, 4, -1, 0, -1, 0 };//laplace锐化模板,4邻域
    QImage newim;
    newim=QImage(image->width(),image->height(),image->format());
    vector<QColor>clr;
    clr.resize(9);
    for (int i = 1; i < image->height() - 1; i++)
        {
            for (int j = 1; j < image->width() - 1; j++)
            {
                clr[0]=image->pixel(i-1,j-1);clr[1]=image->pixel(i-1,j);clr[2]=image->pixel(i-1,j+1);
                clr[3]=image->pixel(i,j-1);clr[4]=image->pixel(i,j);clr[5]=image->pixel(i,j+1);
                clr[6]=image->pixel(i+1,j-1);clr[7]=image->pixel(i+1,j);clr[8]=image->pixel(i+1,j+1);

                //化简后结果   这里使用了 1,1.414,1 的模板（各向同性Sobel算子），与 1,2,1的模板区别不是很大
                float GXr =  4*clr[4].red() - clr[1].red() - clr[3].red() - clr[5].red() - clr[7].red();

                float GXg =  4*clr[4].green() - clr[1].green() - clr[3].green() - clr[5].green() - clr[7].green();

                float GXb =  4*clr[4].blue() - clr[1].blue() - clr[3].blue() - clr[5].blue() - clr[7].blue();

                int valr = LimitValue(sqrt(2*GXr*GXr) + 0.5);
                int valg = LimitValue(sqrt(2*GXg*GXg) + 0.5);
                int valb = LimitValue(sqrt(2*GXb*GXb) + 0.5);
                newim.setPixelColor(i,j,qRgb(valr,valg,valb));
            }
        }
    return newim;
}



//part5 图像噪声

//1.高斯噪声
QImage gaosi(QImage *image,double miu,double sigma);
//2.瑞丽噪声
QImage ruili(QImage *image,double miu,double sigma);
//3.伽马噪声
QImage gama(QImage *image,double miu,double sigma);
//4.均匀噪声
QImage junyun(QImage *image,double miu,double sigma);
//5.椒盐噪声 密度
QImage jiaoyan(QImage *image,int midu);
//6.指数噪声
QImage zhishu(QImage *image,double miu,double sigma);



//part7 图像形状检测(1参识别度)

//1.hough变换
QImage hough(QImage *image,int sbd);//sbd识别度（检测程度）
//2.阈值分割
QImage yuzhi(QImage *image,int sbd);
//3.轮廓跟踪
QImage lunkuo(QImage *image,int sbd);
//4.sobel
QImage xz_sobel(QImage *image,int sbd);
//5.robert
QImage xz_robert(QImage *image,int sbd);
//6.prewitt
QImage xz_prewitt(QImage *image,int sbd);
//7.laplacian
QImage xz_laplacian(QImage *image,int sbd);
//8.log
QImage xz_log(QImage *image,int sbd);


#endif // FUNCS_H

#include "w2.h"
#include "form.h"

#include <QApplication>
//#include <QObject>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    form form;
   // w2 w2;
//    form.setWindowTitle("PS");
    form.show();
    return a.exec();
}

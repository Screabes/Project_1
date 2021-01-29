#include "laba6.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    laba6 w;
    w.show();
    w.resize(1200,800);//запускается при определенных размерах
    return a.exec();
}

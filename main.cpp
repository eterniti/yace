#include "cpkdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CpkDialog w;
    w.show();

    return a.exec();
}

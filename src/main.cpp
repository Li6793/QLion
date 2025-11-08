#include <QApplication>
#include "mainwindow/QLion.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QLion w;
    w.show();

    return a.exec();
}

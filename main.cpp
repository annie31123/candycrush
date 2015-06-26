#include "candycrush.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    candycrush w;
    w.show();

    return a.exec();
}

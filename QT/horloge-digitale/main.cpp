#include <QApplication>
#include "ihmhorloge.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    IHMHorloge w;
    w.show();

    return a.exec();
}

#include <QApplication>
#include "mydialog.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    MyDialog w;
    w.show();

    return app.exec();
}

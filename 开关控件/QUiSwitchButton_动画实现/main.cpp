#include "quiswitchbutton.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QUiSwitchButton w;
    w.show();

    return a.exec();
}

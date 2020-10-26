#include "myclass.h"
#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyClass w;
    w.show();

    MyClass A;
    A.insert(2,"sg");
    A.insert(3,"asb");
    qDebug()<<A[0]<<A[1];
    A.remove(2);
    qDebug()<< A.select(3);

    return a.exec();
}

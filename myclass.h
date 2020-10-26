#ifndef MYCLASS_H
#define MYCLASS_H

#include <QWidget>
#include <QHash>
class MyClass : public QWidget
{
    Q_OBJECT

public:
    MyClass(QWidget *parent = 0);
    ~MyClass();
public:
    bool insert(int key,QString val);
    bool remove(int key);
    QString select(int key);
    QString& operator[](int index)
    {
        return valueHash[index];
    }

   // bool SequeTraver();
    //int  getval(int key);
public:
    QHash<int, QString> valueHash;
    QHash<int, int> indexHash;
};

#endif // MYCLASS_H

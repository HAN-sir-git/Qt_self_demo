#include "myclass.h"
#include <QDebug>
MyClass::MyClass(QWidget *parent)
    : QWidget(parent)
{
}

MyClass::~MyClass()
{

}

bool MyClass::insert(int key, QString val)
{
    QHash<int,int>::iterator it =  indexHash.find(key);
    if(it != indexHash.end())
    {
        int tempindex = it.value();
        valueHash[tempindex] = val;
        return true;

    }
    indexHash[key] = valueHash.size();
    valueHash[valueHash.size()] = val;
    return true;
}

bool MyClass::remove(int key)
{
    QHash<int,int>::iterator  it = indexHash.find(key);

    if(it == indexHash.end())
    {
      //  qDebug() << "容器中不存在key为"<<key<<" ,移除失败";
        return false;
    }
    valueHash.remove(indexHash[key]);
    indexHash.remove(key);
    return true;

}

QString MyClass::select(int key)
{
    QHash<int,int>::iterator  it = indexHash.find(key);

    if(it == indexHash.end())
    {
        return "";
    }
    return valueHash[indexHash[key]];
}

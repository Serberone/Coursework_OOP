#include "publisher.h"

publisher::publisher(QObject *parent) : QObject(parent)
{

}

publisher::publisher(QVector<comix*> ComList, QObject *parent) : QObject(parent){
    this->ComList = ComList;
}

QVector<comix*> publisher::Get_L() {
    return this->ComList;
}

void publisher::setComixList(QVector<comix *> ComList) {
    this->ComList = ComList;
}


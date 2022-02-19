#include "author.h"

author::author(QObject *parent) : QObject(parent)
{

}

author::author(QVector<comix*> TitleList, QObject *parent) : QObject(parent){
    this->TitleList = TitleList;
}

QVector<comix*> author::Get_Lst() {
    return this->TitleList;
};

void author::setLst(QVector<comix *> TitleList) {
    this->TitleList = TitleList;
}

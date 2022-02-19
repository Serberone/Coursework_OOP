#include "genre.h"

genre::genre(QObject *parent) : QObject(parent){}

genre::genre(QString descript, QObject *parent) : QObject(parent){
    this->descript = descript;
}

QString genre::Get_descript() {
    return this->descript;
};

void genre::setDesc(QString descript) {
    this->descript = descript;
}

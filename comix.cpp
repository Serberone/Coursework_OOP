#include "comix.h"

comix::comix(QObject *parent) : QObject(parent){}

comix::comix(QString title, QString author, int numb_of_ch, QString genre, QString status, QString translate, QString lic, QString description, QObject *parent) : QObject(parent){
    this->title = title;
    this->author = author;
    this->numb_of_ch = numb_of_ch;
    this->genre = genre;
    this->status = status;
    this->translate = translate;
    this->lic = lic;
    this->description = description;
}

QString comix::Get_title() {
    return this->title;
}

QString comix::Get_author() {
    return this->author;
}

int comix::Get_numb() {
    return this->numb_of_ch;
}

QString comix::Get_genre() {
    return this->genre;
}

QString comix::Get_status() {
    return this->status;
}

QString comix::Get_translate() {
    return this->translate;
}

QString comix::Get_lic() {
    return this->lic;
}

QString comix::Get_description() {
    return this->description;
}

void comix::setTitle(QString title) {
    this->title = title;
}

void comix::setAuthor(QString author) {
    this->author = author;
}

void comix::setNumbCh(int numb_of_ch) {
    this->numb_of_ch = numb_of_ch;
}

void comix::setGenre(QString genre) {
    this->genre = genre;
}

void comix::setStatus(QString status) {
    this->status = status;
}

void comix::setTranslate(QString translate) {
    this->translate = translate;
}

void comix::setLic(QString lic) {
    this->lic = lic;
}

void comix::setDescript(QString description) {
    this->description = description;
}

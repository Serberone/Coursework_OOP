#include "user.h"

user::user(QObject *parent) : QObject(parent)
{

}

user::user(QString login, QString pass, QString email, QObject *parent) : QObject(parent){
    this->login = login;
    this->pass = pass;
    this->email = email;
}

QString user::Get_login() {
    return this->login;
}

QString user::Get_pass() {
    return this->pass;
}

QString user::Get_email() {
    return this->email;
}

void user::setLogin(QString login) {
    this->login = login;
}

void user::setPass(QString pass) {
    this->pass = pass;
}

void user::setEmail(QString email) {
    this->email = email;
}

#ifndef ADMIN_H
#define ADMIN_H

#include <QObject>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include "user.h"

class Admin : public user
{
    Q_OBJECT
public:
    //Функция возвращает указатель на одиночку
    static Admin* getAdmin();
    QString current_login;

private:
    //Указатель на класс (одиночку)
    static Admin* adm;
    explicit Admin(QObject *parent = nullptr);

signals:

};

#endif // ADMIN_H

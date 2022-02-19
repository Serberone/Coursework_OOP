#ifndef USER_H
#define USER_H

#include <QObject>
#include <QVector>
#include "comix.h"

class user : public QObject
{
    Q_OBJECT
public:
    explicit user(QString login, QString pass, QString email, QObject *parent = nullptr);
    explicit user(QObject *parent = nullptr);
    QString Get_login();
    QString Get_pass();
    QString Get_email();
    void setLogin(QString login);
    void setPass(QString pass);
    void setEmail(QString email);

private:
    QString login;
    QString pass;
    QString email;
signals:

};

#endif // USER_H

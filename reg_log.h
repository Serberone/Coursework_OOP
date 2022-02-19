#ifndef REG_LOG_H
#define REG_LOG_H

#include <QDialog>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include "admin.h"

namespace Ui {
class reg_log;
}

class reg_log : public QDialog
{
    Q_OBJECT

public:
    explicit reg_log(QWidget *parent = nullptr, QString *login = nullptr, QString *pass = nullptr);
    ~reg_log();

private slots:
    void on_registerBtn_clicked();

    void on_loginBtn_clicked();

private:
    Ui::reg_log *ui;
    QString login;
    QString pass;
};

#endif // REG_LOG_H

#ifndef ADMIN_TOOLS_H
#define ADMIN_TOOLS_H

#include <QDialog>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include "comix.h"

namespace Ui {
class admin_tools;
}

class admin_tools : public QDialog
{
    Q_OBJECT

public:
    explicit admin_tools(QWidget *parent = nullptr);
    ~admin_tools();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_refresh_clicked();

private:
    Ui::admin_tools *ui;
};

#endif // ADMIN_TOOLS_H

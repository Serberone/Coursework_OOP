#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include "reg_log.h"
#include "catalog.h"
#include "admin.h"
#include "admin_tools.h"
#include "author.h"
#include "comix.h"
#include "genre.h"
#include "publisher.h"
#include "user.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
   //void openreg_log();

private slots:

    void on_pushButton_clicked();

    void on_admin_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QString login;
    QString pass;
};
#endif // MAINWINDOW_H

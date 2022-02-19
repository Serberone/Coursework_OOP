#ifndef CATALOG_H
#define CATALOG_H

#include <QDialog>
#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
#include <QMessageBox>
#include "comix.h"

namespace Ui {
class Catalog;
}

class Catalog : public QDialog
{
    Q_OBJECT
public:
    explicit Catalog(QWidget *parent = nullptr);
    void ShowCatalog();
    ~Catalog();

private:
    Ui::Catalog *ui;

signals:

private slots:
    void on_use_filtr_clicked();
};

#endif // CATALOG_H

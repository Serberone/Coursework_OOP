#include "catalog.h"
#include "ui_catalog.h"

Catalog::Catalog(QWidget *parent) :
    QDialog(parent), ui(new Ui::Catalog) {
    ui->setupUi(this);
    ShowCatalog();
}

Catalog::~Catalog()
{
    delete ui;
}

void Catalog::ShowCatalog() {
    QSqlQuery catalog;
    catalog.exec("select * from comix");
    int i = 0;
    int size = 0;
    if(catalog.last()) {
        size = catalog.at() + 1;
        catalog.first();
        catalog.previous();
    }
    ui->catalogForm->setRowCount(size);
    while(catalog.next()){
        ui->catalogForm->setItem(i,0,new QTableWidgetItem(catalog.value("ComixId").toString()));
        ui->catalogForm->setItem(i,1,new QTableWidgetItem(catalog.value("title").toString()));
        ui->catalogForm->setItem(i,2,new QTableWidgetItem(catalog.value("numb_of_ch").toString()));
        ui->catalogForm->setItem(i,3,new QTableWidgetItem(catalog.value("stat").toString()));
        ui->catalogForm->setItem(i,4,new QTableWidgetItem(catalog.value("translate").toString()));
        ui->catalogForm->setItem(i,5,new QTableWidgetItem(catalog.value("descript").toString()));
        ui->catalogForm->setItem(i,6,new QTableWidgetItem(catalog.value("g_name").toString()));
        ui->catalogForm->setItem(i,7,new QTableWidgetItem(catalog.value("author").toString()));
        ui->catalogForm->setItem(i,8,new QTableWidgetItem(catalog.value("publisher").toString()));
        i++;
    }
}

void Catalog::on_use_filtr_clicked()
{
    QSqlQuery filtr_ch(QSqlDatabase::database("kursov"));
    int curNum = ui->comboBox->currentIndex();
    QString check = ui->filtr->text();
    switch (curNum) {
    case 0: {
        filtr_ch.prepare(QString("select * from comix where title = :check"));
        filtr_ch.bindValue(":check", check);
        break;
    }
    case 1: {
        filtr_ch.prepare(QString("select * from comix where g_name = :check"));
        filtr_ch.bindValue(":check", check);
        break;
    }
    case 2: {
        filtr_ch.prepare(QString("select * from comix where author = :check"));
        filtr_ch.bindValue(":check", check);
        break;
    }
    case 3: {
        filtr_ch.prepare(QString("select * from comix where publisher = :check"));
        filtr_ch.bindValue(":check", check);
        break;
    }
    }
    filtr_ch.exec();
    int i = 0;
    int size = 0;
    if(filtr_ch.last()) {
        size = filtr_ch.at() + 1;
        filtr_ch.first();
        filtr_ch.previous();
    }
    ui->catalogForm->setRowCount(size);
    while(filtr_ch.next()){
        ui->catalogForm->setItem(i,0,new QTableWidgetItem(filtr_ch.value("ComixId").toString()));
        ui->catalogForm->setItem(i,1,new QTableWidgetItem(filtr_ch.value("title").toString()));
        ui->catalogForm->setItem(i,2,new QTableWidgetItem(filtr_ch.value("numb_of_ch").toString()));
        ui->catalogForm->setItem(i,3,new QTableWidgetItem(filtr_ch.value("stat").toString()));
        ui->catalogForm->setItem(i,4,new QTableWidgetItem(filtr_ch.value("translate").toString()));
        ui->catalogForm->setItem(i,5,new QTableWidgetItem(filtr_ch.value("descript").toString()));
        ui->catalogForm->setItem(i,6,new QTableWidgetItem(filtr_ch.value("g_name").toString()));
        ui->catalogForm->setItem(i,7,new QTableWidgetItem(filtr_ch.value("author").toString()));
        ui->catalogForm->setItem(i,8,new QTableWidgetItem(filtr_ch.value("publisher").toString()));
        i++;
    }
}

#include "admin_tools.h"
#include "ui_admin_tools.h"

admin_tools::admin_tools(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_tools)
{
    ui->setupUi(this);
}

admin_tools::~admin_tools()
{
    delete ui;
}

void admin_tools::on_pushButton_clicked()
{
    QSqlQuery users;
    users.exec("select * from user_");
    int i = 0;
    int size = 0;
    if(users.last()) {
        size = users.at() + 1;
        users.first();
        users.previous();
    }
    ui->tableUsers->setRowCount(size);
    while(users.next()){
        ui->tableUsers->setItem(i,0,new QTableWidgetItem(users.value("UserId").toString()));
        ui->tableUsers->setItem(i,1,new QTableWidgetItem(users.value("login").toString()));
        ui->tableUsers->setItem(i,2,new QTableWidgetItem(users.value("password_").toString()));
        ui->tableUsers->setItem(i,3,new QTableWidgetItem(users.value("email").toString()));
        i++;
    }
}

void admin_tools::on_pushButton_2_clicked()
{
    QSqlQuery qry_log(QSqlDatabase::database("kursov"));
    QString genre_ = ui->lineEdit_6->text();
    QString author_ = ui->lineEdit_7->text();
    QString publisher_ = ui->lineEdit_8->text();
    qry_log.prepare(QString("select g_name from comix where g_name = :g_name"));
    qry_log.bindValue(":g_name", genre_);
    qry_log.exec();
    int size = 0;
    if(qry_log.last()) {
        size = qry_log.at() + 1;
        qry_log.first();
        qry_log.previous();
    }
    if(size == 0) {
        qry_log.prepare(QString("insert into genre(g_name) values (:g_name)"));
        qry_log.bindValue(":g_name", genre_);
        qry_log.exec();
    }
    qry_log.prepare(QString("select author from comix where author = :author"));
    qry_log.bindValue(":author", author_);
    qry_log.exec();
    size = 0;
    if(qry_log.last()) {
        size = qry_log.at() + 1;
        qry_log.first();
        qry_log.previous();
    }
    if(size == 0) {
        qry_log.prepare(QString("insert into author(author) values (:author)"));
        qry_log.bindValue(":author", author_);
        qry_log.exec();
    }
    qry_log.prepare(QString("select publisher from comix where publisher = :publisher"));
    qry_log.bindValue(":publisher", publisher_);
    qry_log.exec();
    size = 0;
    if(qry_log.last()) {
        size = qry_log.at() + 1;
        qry_log.first();
        qry_log.previous();
    }
    if(size == 0){
        qry_log.prepare(QString("insert into publisher(publisher) values (:publisher)"));
        qry_log.bindValue(":publisher", publisher_);
        qry_log.exec();
    }
    QString title_ = ui->lineEdit->text();
    int numb_of_ch_ = ui->lineEdit_2->text().toInt();
    QString stat_ = ui->lineEdit_3->text();
    QString translate_ = ui->lineEdit_4->text();
    QString descript_ = ui->lineEdit_5->text();
    qry_log.prepare(QString("insert into comix(title, numb_of_ch, stat, translate, descript, g_name, author, publisher) values (:title, :numb_of_ch, :stat, :translate, :descript, :g_name, :author, :publisher)"));
    qry_log.bindValue(":title", title_);
    qry_log.bindValue(":numb_of_ch", numb_of_ch_);
    qry_log.bindValue(":stat", stat_);
    qry_log.bindValue(":translate", translate_);
    qry_log.bindValue(":descript", descript_);
    qry_log.bindValue(":g_name", genre_);
    qry_log.bindValue(":author", author_);
    qry_log.bindValue(":publisher", publisher_);
    qry_log.exec();
    QMessageBox::information(this, "Успешно!", "Добавление прошло успешно!");
}

void admin_tools::on_pushButton_3_clicked()
{
    QSqlQuery qry_del(QSqlDatabase::database("kursov"));
    int id_del = ui->id_line->text().toInt();
    qry_del.prepare(QString("delete from comix where ComixId = :id"));
    qry_del.bindValue(":id", id_del);
    qry_del.exec();
    QMessageBox::information(this, "Успешно!", "Удаление прошло успешно!");
}

void admin_tools::on_refresh_clicked()
{
    QSqlQuery refr;
    refr.exec("select ComixId, title from comix");
    int i = 0;
    int size = 0;
    if(refr.last()) {
        size = refr.at() + 1;
        refr.first();
        refr.previous();
    }
    ui->refreshTable->setRowCount(size);
    while(refr.next()){
        ui->refreshTable->setItem(i,0,new QTableWidgetItem(refr.value("ComixId").toString()));
        ui->refreshTable->setItem(i,1,new QTableWidgetItem(refr.value("title").toString()));
        i++;
    }
}

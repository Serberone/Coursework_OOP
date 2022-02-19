#include "reg_log.h"
#include "ui_reg_log.h"

reg_log::reg_log(QWidget *parent, QString *login, QString *pass) :
    QDialog(parent),
    ui(new Ui::reg_log)
{
    this->login = *login;
    this->pass = *pass;
    ui->setupUi(this);
    ui->username->setPlaceholderText("Введите логин");
    ui->password->setPlaceholderText("Введите пароль");
    ui->email->setPlaceholderText("Введите e-mail");
    ui->usernameLogin->setPlaceholderText("Введите логин");
    ui->passwordLogin->setPlaceholderText("Введите пароль");
}

reg_log::~reg_log()
{
    delete ui;
}

void reg_log::on_registerBtn_clicked()
{
    QSqlQuery qry;
    QString username = ui->username->text();
    QString password = ui->password->text();
    QString email = ui->email->text();

    qry.clear();
    qry.prepare("insert into user_(login, password_, email) values (:username, :password, :email)");
    qry.bindValue(":username", username);
    qry.bindValue(":password", password);
    qry.bindValue(":email", email);
    if(qry.exec()) {
        QMessageBox::information(this, "Успешно!", "Добавление прошло успешно!");
    } else {
        QMessageBox::information(this, "Неудачно!", "Добавление не произошло!");
    }
}

void reg_log::on_loginBtn_clicked()
{
    QSqlQuery qrylog(QSqlDatabase::database("kursov"));
    login = ui->usernameLogin->text();
    pass = ui->passwordLogin->text();
    qrylog.prepare(QString("select * from user_ where login = :login and password_ = :pass"));
    qrylog.bindValue(":login", login);
    qrylog.bindValue(":pass", pass);
    qrylog.exec();
    int size = 0;
    if(qrylog.last()) {
        size = qrylog.at() + 1;
        qrylog.first();
        qrylog.previous();
    }
    if(size == 0) {
        QMessageBox::information(this, "Неудачно!", "Неверный логин или пароль!");
    } else {
        while(qrylog.next()) {
            QMessageBox::information(this, "Успех!", "Вход выполнен!");
            Admin *admin = Admin::getAdmin();
            admin->current_login = login;
            close();
        }
    }
}


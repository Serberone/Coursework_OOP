#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Подключение бд
    db = QSqlDatabase::addDatabase("QODBC");
    db.setHostName("127.0.0.1");
    db.setPort(3306);
    db.setDatabaseName("kursov");
    db.setUserName("root");
    db.setPassword("1234");
    bool ok = db.open();
    if (ok){
    // Если бд подключилась выводим сообщение об успехе
        QMessageBox::information(this, "База данных", "Подключение произошло успешно!");
        }
    else {
    // Иначе, выводим сообщение о неудаче и блокируем кнопки сохранения и загрузки
        QMessageBox::warning(this, "База данных", "Не удалось подключиться к базе данных!");
    }
    reg_log dialog(this, &login, &pass);
    dialog.setModal(true);
    dialog.exec();
    Admin *admin = Admin::getAdmin();
    ui->user_login->setText(admin->current_login);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Catalog cal(this);
    cal.setModal(true);
    cal.exec();
}

void MainWindow::on_admin_clicked()
{
    Admin *admin = Admin::getAdmin();
    if(admin->current_login == "admin") {
        admin_tools adm(this);
        adm.setModal(true);
        adm.exec();
    } else {
        QMessageBox::warning(this, "Администрация", "Вы не имеете права администратора!");
    }
}

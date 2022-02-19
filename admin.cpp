#include "admin.h"

Admin::Admin(QObject *parent) {}

Admin* Admin::adm = 0;

Admin* Admin::getAdmin() {
// Если указаетль установлен на 0, то инициализируем класс
    if (adm == 0)
        adm = new Admin(nullptr);
    return adm;
}

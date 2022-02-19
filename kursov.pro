QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    admin_tools.cpp \
    author.cpp \
    catalog.cpp \
    comix.cpp \
    genre.cpp \
    main.cpp \
    mainwindow.cpp \
    publisher.cpp \
    reg_log.cpp \
    user.cpp

HEADERS += \
    admin.h \
    admin_tools.h \
    author.h \
    catalog.h \
    comix.h \
    genre.h \
    mainwindow.h \
    publisher.h \
    reg_log.h \
    user.h

FORMS += \
    admin_tools.ui \
    catalog.ui \
    mainwindow.ui \
    reg_log.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

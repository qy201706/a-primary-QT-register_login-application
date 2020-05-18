#-------------------------------------------------
#
# Project created by QtCreator 2020-05-13T22:24:57
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = register_login
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    logindlg.cpp \
    register.cpp \
    back_pwd.cpp \
    modify_pwd.cpp \
    insertdialog.cpp \
    deletedialog.cpp \
    selectdialog.cpp \
    updatedialog.cpp \
    salary_demo.cpp \
    modify_demo.cpp \
    add_salary.cpp

HEADERS += \
        mainwindow.h \
    logindlg.h \
    register.h \
    back_pwd.h \
    modify_pwd.h \
    insertdialog.h \
    deletedialog.h \
    selectdialog.h \
    updatedialog.h \
    salary_demo.h \
    modify_demo.h \
    add_salary.h

FORMS += \
        mainwindow.ui \
    logindlg.ui \
    register.ui \
    back_pwd.ui \
    modify_pwd.ui \
    insertdialog.ui \
    deletedialog.ui \
    selectdialog.ui \
    updatedialog.ui \
    salary_demo.ui \
    modify_demo.ui \
    add_salary.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

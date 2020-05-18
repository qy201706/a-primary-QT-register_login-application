#include "mainwindow.h"
#include "logindlg.h"
#include <QApplication>
#include <iostream>

using namespace std;

bool connectionDatabes(QSqlDatabase &db)
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setDatabaseName("db_login_and_register");
    db.setUserName("root");
    db.setPassword("root");
    //db.setConnectOptions("SSL_KEY=client-key.pem;SSL_CERT=client-cert.pem;SSL_CA=ca-cert.pem;CLIENT_IGNORE_SPACE=1");
    if(db.open())
    {
        qDebug() << "connected!!";
    }
    else
    {
        qDebug()<<"fail to connect mysql:"<<db.lastError().text();
        return false;
    }

    return true;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase database;
    connectionDatabes(database);
    MainWindow w;
    Logindlg l;
    if(l.exec() == QDialog::Accepted){
        if(l.admin_signal == 1)
            w.is_admin = 1; //设置为管理员权限
        w.show();
    }

    return a.exec();
}

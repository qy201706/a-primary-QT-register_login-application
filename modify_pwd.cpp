#include "modify_pwd.h"
#include "ui_modify_pwd.h"
#include "back_pwd.h"
#include "logindlg.h"

#include <QLineEdit>
#include <QMessageBox>
#include <QtSql>

Modify_pwd::Modify_pwd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modify_pwd)
{
    ui->setupUi(this);
}

Modify_pwd::~Modify_pwd()
{
    delete ui;
}

void Modify_pwd::on_pushButton_clicked()
{
    QString pwd1;
    QString pwd2;
    QString user;
    user = ui->admin->text();
    pwd1 = ui->n_pwd->text();
    pwd2 = ui->n_pwd2->text();
    if(pwd1 != pwd2){
        QMessageBox::warning(this, "error", "两次输入不一致");
        ui->n_pwd->clear();
        ui->n_pwd2->clear();
        ui->n_pwd->setFocus();
    }else {
        QString S = QString("update admin_pwd set pwd = '%1' where admin ='%2'").arg(pwd1).arg(user);
        QSqlQuery query;
        query.exec(S);
        this->close();
        auto login = new Logindlg;
        login->show();
    }

}

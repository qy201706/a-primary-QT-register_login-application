#include "back_pwd.h"
#include "ui_back_pwd.h"
#include "modify_pwd.h"
#include "logindlg.h"

#include <QLineEdit>
#include <QMessageBox>
#include <QtSql>

Back_pwd::Back_pwd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Back_pwd)
{
    ui->setupUi(this);

    ui->r_pwd->setEchoMode(QLineEdit::PasswordEchoOnEdit);
}

Back_pwd::~Back_pwd()
{
    delete ui;
}

void Back_pwd::on_verify_clicked()
{
    QString user;
    QString pwd;
    user = ui->admin->text();//获取用户名
    pwd = ui->r_pwd->text();//获取密码
    if(user == "")
        QMessageBox::warning(this,"","用户名不能为空！");
    else if(pwd == "")
        QMessageBox::warning(this,"","密码不能为空！");
    else {
        QString S = QString("select * from admin_pwd where admin='%1' and pwd = '%2'").arg(user).arg(pwd);
        QSqlQuery query;
        if(query.exec(S) && query.next()){
            auto modify = new Modify_pwd;
            modify->show();
            this->close();
        }
    }
}

#include "register.h"
#include "ui_register.h"
#include "logindlg.h"

#include <QLineEdit>
#include <QMessageBox>
#include <QtSql>

Register::Register(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_clicked()
{
    QString user;
    QString pwd;
    user = ui->admin->text();//获取用户名
    pwd = ui->pwd->text();//获取密码
    if(user == "")
        QMessageBox::warning(this,"","用户名不能为空！");
    else if(pwd == "")
        QMessageBox::warning(this,"","密码不能为空！");
    else
    {

        //sql语句在数据库中进行查询验证
        QString i=QString("insert into admin_pwd values ('%1','%2'); ").arg(user).arg(pwd);
        QString S =QString("select * from admin_pwd where admin='%1' ").arg(user);
        QSqlQuery query;
        if(query.exec(S)&&query.first())
            QMessageBox::warning(this, "Error", "用户名重复！！！");
        else if(query.exec(i))
        {
             QMessageBox::information(this, "注册成功", "注册成功！！！", QMessageBox::Yes);
             auto login = new Logindlg;
             login->show();
             this->close();
        }
        else
            QMessageBox::warning(this, "Error", "注册失败，请重试！！！");

        ui->admin->clear();
        ui->pwd->clear();
        ui->admin->setFocus();

    }
}

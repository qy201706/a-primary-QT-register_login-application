#include "logindlg.h"
#include "ui_logindlg.h"
#include "register.h"
#include "back_pwd.h"

#include <QLineEdit>
#include <QMessageBox>
#include <QtSql>
#include <QDebug>

Logindlg::Logindlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Logindlg)
{
    ui->setupUi(this);

    //用户名输入提示
    ui->admin->setPlaceholderText("請输入用户名");

    //密码输入提示
    ui->pwd->setPlaceholderText("请输入密码");

    //密码显示为圆点
    ui->pwd->setEchoMode(QLineEdit::Password);

    //设置登录出错次数初始为0
    times = 0;
}

Logindlg::~Logindlg()
{
    delete ui;
}

void Logindlg::on_launch_clicked()
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
        QString S =QString("select * from admin_pwd where admin='%1' and pwd='%2' ").arg(user).arg(pwd);
        QSqlQuery query;
        if(query.exec(S) && query.first()){
            QMessageBox::information(this, "info", "登陆成功");
            if(user == "admin") //判断是否为管理员用户
                this->admin_signal = 1;
            accept();
        }
        else
        {
            QMessageBox::warning(this, "Error", "用户名或密码错误！！！");

            if(++times > 3){ //登录出错数不能超过三次
                QMessageBox::warning(this, "Error", "输错超过三次请重新启动软件！！");
                exit(0);
            }
            qDebug() << "is:" << times;
            ui->admin->clear();
            ui->pwd->clear();
            ui->admin->setFocus();
        }

    }
}

void Logindlg::on_register_2_clicked()
{
    auto reg = new Register;
    reg->show();
    this->close();
}

void Logindlg::on_back_pwd_clicked()
{
    auto back = new Back_pwd;
    back->show();
    this->close();
}

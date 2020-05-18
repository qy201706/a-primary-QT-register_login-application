#include "add_salary.h"
#include "ui_add_salary.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>

Add_salary::Add_salary(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add_salary)
{
    ui->setupUi(this);
}

Add_salary::~Add_salary()
{
    delete ui;
}

void Add_salary::on_pushButton_clicked()
{
    QString num = ui->num->text();
    QString del = ui->del->text();

    QSqlQuery query;
    QString I = QString("insert into salary_demo values('%1', 0, '%2')").arg(num).arg(del);
    QString S1 = QString("select * from people_department where id='%1'").arg(num);
    query.exec(I);
    query.exec(S1);
    query.next();
    QString S2 = QString("select * from salary_standard where salary_type='%1'").arg(query.value(2).toString());
    query.exec(S2);
    query.next();
    //qDebug() << "S:" << query.value(1).toInt();
    QString U = QString("update salary_demo set 应发项目='%1' where id='%2'").arg(query.value(1).toString()).arg(num);
    if(query.exec(U)){
        QMessageBox::information(this, "提示", "修改成功!");
    }else{
        QMessageBox::information(this, "提示", "修改失败!");
    }
    this->close();
}

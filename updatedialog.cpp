#include "updatedialog.h"
#include "ui_updatedialog.h"
#include "mainwindow.h"
#include <QSqlQuery>
#include <QMessageBox>

Updatedialog::Updatedialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Updatedialog)
{
    ui->setupUi(this);
}

Updatedialog::~Updatedialog()
{
    delete ui;
}

void Updatedialog::on_pushButton_clicked()
{
    QString num = ui->num->text();
    QString name = ui->name->text();
    QString type = ui->type->text();
    QString department = ui->department->text();

    QSqlQuery query;
    QString U = QString("update people_department set name='%1', type='%2', department='%3' where id='%4'").arg(name).arg(type)
            .arg(department).arg(num);
    if(query.exec(U)){
        QMessageBox::information(this,"提示","修改成功");
    }else{
        QMessageBox::information(this, "提示", "修改失败");
    }
    this->close();
}

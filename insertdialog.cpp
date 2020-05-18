#include "insertdialog.h"
#include "ui_insertdialog.h"
#include "mainwindow.h"
#include <QSqlQuery>

Insertdialog::Insertdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Insertdialog)
{
    ui->setupUi(this);
}

Insertdialog::~Insertdialog()
{
    delete ui;
}

void Insertdialog::on_insert_button_clicked()
{
    if(ui->number->text().isEmpty() || ui->type->text().isEmpty() || ui->department->text().isEmpty() || ui->name->text().isEmpty()){
            QMessageBox::information(this,"提示","请输入完整");
    }
    else{
        QString number = ui->number->text();
        QString name = ui->name->text();
        QString type = ui->type->text();
        QString department = ui->department->text();
        QString I = QString("Insert into people_department values(\"%1\", \"%2\", \"%3\", \"%4\")").arg(number).arg(name).arg(type).arg(department);
        QString S = QString("select * from people_department where id=%1").arg(number);
        QSqlQuery query;
        if(query.exec(S) && query.first())
            QMessageBox::information(this,"提示","员工信息已经存在！");
        if(query.exec(I))
            QMessageBox::information(this,"提示","插入成功");
        else
            QMessageBox::information(this,"提示","插入失败");
    }
    this->close();
}

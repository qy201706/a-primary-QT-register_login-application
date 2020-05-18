#include "deletedialog.h"
#include "ui_deletedialog.h"
#include "mainwindow.h"
#include <QSqlQuery>

Deletedialog::Deletedialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Deletedialog)
{
    ui->setupUi(this);
}

Deletedialog::~Deletedialog()
{
    delete ui;
}

void Deletedialog::on_pushButton_clicked()
{
    QString num = ui->num->text();
    QString D = QString("delete from people_department where id='%1'").arg(num);

    QSqlQuery query;
    if(query.exec(D))
        QMessageBox::information(this, "提示", "删除成功");
    else
        QMessageBox::information(this, "提示", "删除失败");
    this->close();
}

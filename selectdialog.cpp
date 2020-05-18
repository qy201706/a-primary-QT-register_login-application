#include "selectdialog.h"
#include "ui_selectdialog.h"
#include <QSqlQuery>
#include <QDebug>

Selectdialog::Selectdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Selectdialog)
{
    ui->setupUi(this);

    ui->demo->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->demo->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    ui->demo->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->demo->setRowCount(1);
    ui->demo->setColumnCount(3);
    QString str = "员工号,工资,税后工资";
    QStringList list = str.split(',');
    ui->demo->setHorizontalHeaderLabels(list); //表头

}

Selectdialog::~Selectdialog()
{
    delete ui;
}

void Selectdialog::on_pushButton_clicked()
{
    QString num = ui->num->text();
    QSqlQuery query;
    QString S = QString("select * from salary_demo where id='%1'").arg(num);
    query.exec(S);
    query.next();
    //qDebug() << "S:" << query.value(1).toInt() << query.value(2).toInt();
    double c = query.value(1).toDouble()-query.value(2).toDouble();
    //qDebug() << c;
    QString I = QString("insert into salary_final values('%1', '%2', '%3')").arg(num).arg(c).arg(0.8*c);
    QString S2 = QString("select * from salary_final where id='%1'").arg(num);
    query.exec(I);
    query.exec(S2);
    query.next();
    ui->demo->setItem(0, 0, new QTableWidgetItem(query.value(0).toString()));
    ui->demo->setItem(0, 1, new QTableWidgetItem(query.value(1).toString()));
    ui->demo->setItem(0, 2, new QTableWidgetItem(query.value(2).toString()));

}

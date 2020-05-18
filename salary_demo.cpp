#include "salary_demo.h"
#include "ui_salary_demo.h"
#include <QSqlQuery>

Salary_demo::Salary_demo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Salary_demo)
{
    ui->setupUi(this);

    ui->demo->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->demo->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    ui->demo->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->demo->setRowCount(4);
    ui->demo->setColumnCount(2);
    QString str = "员工类型(0:普通员工，1：干事，2：经理，3：董事),工资标准";
    QStringList list = str.split(',');
    ui->demo->setHorizontalHeaderLabels(list); //表头

    QSqlQuery query;
    QString S = QString("select * from salary_standard");
    query.exec(S);
    int i = 0;
    while (query.next()) {
        ui->demo->setItem(i, 0, new QTableWidgetItem(query.value(0).toString()));
        ui->demo->setItem(i, 1, new QTableWidgetItem(query.value(1).toString()));
        ++i;
    }
}

Salary_demo::~Salary_demo()
{
    delete ui;
}

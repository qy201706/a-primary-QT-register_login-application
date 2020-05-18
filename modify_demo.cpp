#include "modify_demo.h"
#include "ui_modify_demo.h"
#include <QSqlQuery>
#include <QMessageBox>

Modify_demo::Modify_demo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modify_demo)
{
    ui->setupUi(this);
}

Modify_demo::~Modify_demo()
{
    delete ui;
}

void Modify_demo::on_pushButton_clicked()
{
    QStringList t = {ui->t0->text(), ui->t1->text(), ui->t2->text(), ui->t3->text()};
    QSqlQuery query;
    for(int i = 0; i < t.size(); ++i){
        QString U = QString("update salary_standard set standard='%1' where salary_type='%2'").arg(t[i]).arg(i);
        if(!query.exec(U)){
            QMessageBox::information(this, "提示", "插入失败");
            this->close();
        }
    }
    QMessageBox::information(this, "提示", "修改完成");
    this->close();
}

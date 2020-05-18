#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "insertdialog.h"
#include <string>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("主界面");

    //设置滚动条
    ui->view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    ui->view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    QSqlQuery query;
    query.exec(QString("select * from people_department"));

    //设置行数、列数、表头
    t=0;
    while(query.next())
    {
        ui->view->insertRow(t);
        t++;
    }
//    qDebug() << t << endl;
    ui->view->setColumnCount(4);
    QString str = "员工号,姓名,员工类型,所属部门";
    QStringList list = str.split(',');
    ui->view->setHorizontalHeaderLabels(list); //表头

    //刷新表的定时器
    tabletime = new QTimer(this);
    tabletime->start(2000);
    connect(tabletime,SIGNAL(timeout()),this,SLOT(tabletimeslot()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_salary_demo_clicked() //显示工资标准按钮
{
    salary_demo.show();
}

void MainWindow::on_query_salary_clicked() //查询员工工资按钮
{
    people_select.show();
}

void MainWindow::on_add_people_clicked() //添加员工按钮，管理员操作
{
    if(this->is_admin == 1){
        QMessageBox::information(this, "提示", "你是管理员");
        people_insert.show();
    }else {
        QMessageBox::information(this, "提示", "拒绝访问");
    }
}

void MainWindow::on_delete_people_clicked() //删除员工信息按钮，管理员操作
{
    if(this->is_admin == 1){
        QMessageBox::information(this, "提示", "你是管理员");
        people_delete.show();
    }else {
        QMessageBox::information(this, "提示", "拒绝访问");
    }
}

void MainWindow::tabletimeslot() //动态表显示员工信息
{
    ui->view->clearContents();
    //QString studentname,studentnumber,studentcollege,studentage,studentsex;
    QSqlQuery query;
    query.exec("select * from people_department");
    int t=0;
    while(query.next())
    {
        ui->view->setItem(t,0,new QTableWidgetItem(query.value(0).toString()));
        ui->view->setItem(t,1,new QTableWidgetItem(query.value(1).toString()));
        ui->view->setItem(t,2,new QTableWidgetItem(query.value(2).toString()));
        ui->view->setItem(t,3,new QTableWidgetItem(query.value(3).toString()));
//        qDebug()<<query.value(0).toString()<<","<<query.value(1).toString()<<","<<query.value(2).toString()<<
//                  ","<<query.value(3).toString();
        t++;
    }
}

void MainWindow::on_admin_clicked() //判断管理员按钮，并且进行工资标准设置
{
    if(this->is_admin == 1){
        QMessageBox::information(this, "提示", "你是管理员");
        modify_demo.show();
    }else {
        QMessageBox::information(this, "提示", "拒绝访问");
    }
}

void MainWindow::on_update_salary_clicked() //更新员工信息按钮，管理员操作
{
    //判断是否为管理员
    if(this->is_admin == 1){
        QMessageBox::information(this, "提示", "你是管理员");
        people_update.show();
    }else {
        QMessageBox::information(this, "提示", "拒绝访问");
    }
}

void MainWindow::on_del_detals_clicked() //管理员设置员工扣费明细
{
    if(this->is_admin == 1){
        QMessageBox::information(this, "提示", "你是管理员");
        add_salary.show();
    }else {
        QMessageBox::information(this, "提示", "拒绝访问");
    }
}

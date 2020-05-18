#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QDebug>
#include <QStringList>
#include <QSqlQuery>
#include <QSqlError>
#include <QString>
#include <QtWidgets>
#include <QTimer>
#include "deletedialog.h"
#include "insertdialog.h"
#include "selectdialog.h"
#include "updatedialog.h"
#include "salary_demo.h"
#include "modify_demo.h"
#include "add_salary.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    int is_admin; //0表示非管理员用户,1表示管理员用户
    ~MainWindow();

private slots:
    void on_salary_demo_clicked();

    void on_query_salary_clicked();

    void on_add_people_clicked();

    void on_delete_people_clicked();

    void tabletimeslot();

    void on_admin_clicked();

    void on_update_salary_clicked();

    void on_del_detals_clicked();

private:
    Ui::MainWindow *ui;
    int t; //用来进行循环的标记，约等于行号
    QTimer *tabletime;
    Deletedialog people_delete;
    Insertdialog people_insert;
    Updatedialog people_update;
    Selectdialog people_select;
    Salary_demo salary_demo;
    Modify_demo modify_demo;
    Add_salary add_salary;
};

#endif // MAINWINDOW_H

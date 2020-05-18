#ifndef ADD_SALARY_H
#define ADD_SALARY_H

#include <QDialog>

namespace Ui {
class Add_salary;
}

class Add_salary : public QDialog
{
    Q_OBJECT

public:
    explicit Add_salary(QWidget *parent = nullptr);
    ~Add_salary();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Add_salary *ui;
};

#endif // ADD_SALARY_H

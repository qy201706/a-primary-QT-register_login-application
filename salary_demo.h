#ifndef SALARY_DEMO_H
#define SALARY_DEMO_H

#include <QDialog>

namespace Ui {
class Salary_demo;
}

class Salary_demo : public QDialog
{
    Q_OBJECT

public:
    explicit Salary_demo(QWidget *parent = nullptr);
    ~Salary_demo();

private:
    Ui::Salary_demo *ui;
};

#endif // SALARY_DEMO_H

#ifndef MODIFY_DEMO_H
#define MODIFY_DEMO_H

#include <QDialog>

namespace Ui {
class Modify_demo;
}

class Modify_demo : public QDialog
{
    Q_OBJECT

public:
    explicit Modify_demo(QWidget *parent = nullptr);
    ~Modify_demo();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Modify_demo *ui;
};

#endif // MODIFY_DEMO_H

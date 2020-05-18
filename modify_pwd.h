#ifndef MODIFY_PWD_H
#define MODIFY_PWD_H

#include <QDialog>

namespace Ui {
class Modify_pwd;
}

class Modify_pwd : public QDialog
{
    Q_OBJECT

public:
    explicit Modify_pwd(QWidget *parent = nullptr);
    ~Modify_pwd();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Modify_pwd *ui;
};

#endif // MODIFY_PWD_H

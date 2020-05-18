#ifndef BACK_PWD_H
#define BACK_PWD_H

#include <QDialog>

namespace Ui {
class Back_pwd;
}

class Back_pwd : public QDialog
{
    Q_OBJECT

public:
    explicit Back_pwd(QWidget *parent = nullptr);
    ~Back_pwd();

private slots:
    void on_verify_clicked();

private:
    Ui::Back_pwd *ui;
};

#endif // BACK_PWD_H

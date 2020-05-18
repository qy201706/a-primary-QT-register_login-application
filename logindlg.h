#ifndef LOGINDLG_H
#define LOGINDLG_H

#include <QDialog>

namespace Ui {
class Logindlg;
}

class Logindlg : public QDialog
{
    Q_OBJECT

public:
    explicit Logindlg(QWidget *parent = nullptr);

    int times; //登录次数
    int admin_signal; //判断是否为管理员
    ~Logindlg();

private slots:
    void on_launch_clicked();

    void on_register_2_clicked();

    void on_back_pwd_clicked();

private:
    Ui::Logindlg *ui;
};

#endif // LOGINDLG_H

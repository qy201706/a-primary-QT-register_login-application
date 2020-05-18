#ifndef SELECTDIALOG_H
#define SELECTDIALOG_H

#include <QDialog>

namespace Ui {
class Selectdialog;
}

class Selectdialog : public QDialog
{
    Q_OBJECT

public:
    explicit Selectdialog(QWidget *parent = nullptr);
    ~Selectdialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Selectdialog *ui;
};

#endif // SELECTDIALOG_H

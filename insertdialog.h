#ifndef INSERTDIALOG_H
#define INSERTDIALOG_H

#include <QDialog>

namespace Ui {
class Insertdialog;
}

class Insertdialog : public QDialog
{
    Q_OBJECT

public:
    explicit Insertdialog(QWidget *parent = nullptr);
    ~Insertdialog();

private slots:
    void on_insert_button_clicked();

private:
    Ui::Insertdialog *ui;
};

#endif // INSERTDIALOG_H

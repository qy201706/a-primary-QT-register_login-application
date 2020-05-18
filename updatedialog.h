#ifndef UPDATEDIALOG_H
#define UPDATEDIALOG_H

#include <QDialog>

namespace Ui {
class Updatedialog;
}

class Updatedialog : public QDialog
{
    Q_OBJECT

public:
    explicit Updatedialog(QWidget *parent = nullptr);
    ~Updatedialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Updatedialog *ui;
};

#endif // UPDATEDIALOG_H

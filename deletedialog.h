#ifndef DELETEDIALOG_H
#define DELETEDIALOG_H

#include <QDialog>

namespace Ui {
class Deletedialog;
}

class Deletedialog : public QDialog
{
    Q_OBJECT

public:
    explicit Deletedialog(QWidget *parent = nullptr);
    ~Deletedialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Deletedialog *ui;
};

#endif // DELETEDIALOG_H

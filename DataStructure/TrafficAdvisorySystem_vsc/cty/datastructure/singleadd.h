#ifndef SINGLEADD_H
#define SINGLEADD_H

#include <QDialog>

namespace Ui {
class singleadd;
}

class singleadd : public QDialog
{
    Q_OBJECT

public:
    explicit singleadd(QWidget *parent = nullptr);
    ~singleadd();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::singleadd *ui;
};

#endif // SINGLEADD_H

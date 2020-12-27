#ifndef REMOVECITY_H
#define REMOVECITY_H

#include <QDialog>

namespace Ui {
class removecity;
}

class removecity : public QDialog
{
    Q_OBJECT

public:
    explicit removecity(QWidget *parent = nullptr);
    ~removecity();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::removecity *ui;
};

#endif // REMOVECITY_H

#ifndef ADDPATH_H
#define ADDPATH_H

#include <QDialog>

namespace Ui {
class addpath;
}

class addpath : public QDialog
{
    Q_OBJECT

public:
    explicit addpath(QWidget *parent = nullptr);
    ~addpath();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::addpath *ui;
};

#endif // ADDPATH_H

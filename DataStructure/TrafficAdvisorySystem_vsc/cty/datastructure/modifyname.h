#ifndef MODIFYNAME_H
#define MODIFYNAME_H

#include <QDialog>

namespace Ui {
class modifyname;
}

class modifyname : public QDialog
{
    Q_OBJECT

public:
    explicit modifyname(QWidget *parent = nullptr);
    ~modifyname();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::modifyname *ui;
};

#endif // MODIFYNAME_H

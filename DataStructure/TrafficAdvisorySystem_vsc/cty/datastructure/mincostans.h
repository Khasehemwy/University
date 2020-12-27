#ifndef MINCOSTANS_H
#define MINCOSTANS_H

#include <QDialog>

namespace Ui {
class mincostans;
}

class mincostans : public QDialog
{
    Q_OBJECT

public:
    explicit mincostans(QWidget *parent = nullptr);
    ~mincostans();

private:
    Ui::mincostans *ui;
};

#endif // MINCOSTANS_H

#ifndef mindistANS_H
#define mindistANS_H

#include <QDialog>

namespace Ui {
class mindistans;
}

class mindistans : public QDialog
{
    Q_OBJECT

public:
    explicit mindistans(QWidget *parent = nullptr);
    ~mindistans();

private:
    Ui::mindistans *ui;
};

#endif // mindistANS_H

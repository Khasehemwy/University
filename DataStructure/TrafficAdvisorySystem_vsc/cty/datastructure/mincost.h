#ifndef MINCOST_H
#define MINCOST_H

#include <QDialog>
#include <vector>
#include <string>

namespace Ui {
class mincost;
}

class mincost : public QDialog
{
    Q_OBJECT

public:
    explicit mincost(QWidget *parent = nullptr);
    ~mincost();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::mincost *ui;
};

extern std::vector<std::string> mans;
#endif // MINCOST_H

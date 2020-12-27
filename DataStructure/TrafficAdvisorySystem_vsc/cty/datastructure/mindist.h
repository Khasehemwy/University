#ifndef mindist_H
#define mindist_H

#include <QDialog>
#include <vector>
#include <string>

namespace Ui {
class mindist;
}

class mindist : public QDialog
{
    Q_OBJECT

public:
    explicit mindist(QWidget *parent = nullptr);
    ~mindist();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::mindist *ui;
};

extern std::vector<std::string> mdans;
#endif // mindist_H

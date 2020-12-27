#include "mincost.h"
#include "ui_mincost.h"
#include "Class.h"
#include "mincostans.h"

std::vector<std::string> mans;

mincost::mincost(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mincost)
{
    ui->setupUi(this);
}

mincost::~mincost()
{
    delete ui;
}

void mincost::on_buttonBox_accepted()
{
    mans = cities.findCheapestPath(ui->start->text().toStdString(),ui->end->text().toStdString(),ui->method->currentIndex());
    mincostans* ans = new mincostans;
    ans->show();
}

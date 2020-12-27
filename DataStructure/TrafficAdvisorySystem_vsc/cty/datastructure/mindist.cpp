#include "mindist.h"
#include "ui_mindist.h"
#include "Class.h"
#include "mindistans.h"

std::vector<std::string> mdans;

mindist::mindist(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mindist)
{
    ui->setupUi(this);
}

mindist::~mindist()
{
    delete ui;
}

void mindist::on_buttonBox_accepted()
{
    mdans = cities.findFastestPath(ui->start->text().toStdString(),ui->end->text().toStdString(),ui->method->currentIndex());
    mindistans* dans = new mindistans;
    dans->show();
}

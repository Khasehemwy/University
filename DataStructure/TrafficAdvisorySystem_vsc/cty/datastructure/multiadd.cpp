#include "multiadd.h"
#include "singleadd.h"
#include "ui_multiadd.h"

multiadd::multiadd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::multiadd)
{
    ui->setupUi(this);
}

multiadd::~multiadd()
{
    delete ui;
}

void multiadd::on_buttonBox_accepted()
{
    for(int i=0;i<ui->number->text().toInt();i++) {
        singleadd* sadd = new singleadd;
        sadd->exec();
    }
}

void multiadd::on_buttonBox_rejected()
{
    this->destroy();
}

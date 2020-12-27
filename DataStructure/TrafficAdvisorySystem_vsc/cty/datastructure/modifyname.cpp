#include "modifyname.h"
#include "Class.h"
#include "ui_modifyname.h"

modifyname::modifyname(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifyname)
{
    ui->setupUi(this);
}

modifyname::~modifyname()
{
    delete ui;
}

void modifyname::on_buttonBox_accepted()
{
    cities.reviseCityName(ui->oldname->text().toStdString(),ui->newname->text().toStdString());
}

void modifyname::on_buttonBox_rejected()
{
    this->destroy();
}

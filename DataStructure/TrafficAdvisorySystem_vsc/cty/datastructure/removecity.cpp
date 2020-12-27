#include "removecity.h"
#include "Class.h"
#include "ui_removecity.h"

removecity::removecity(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::removecity)
{
    ui->setupUi(this);
}

removecity::~removecity()
{
    delete ui;
}

void removecity::on_buttonBox_accepted()
{
    cities.eraseCity(ui->name->text().toStdString());
}

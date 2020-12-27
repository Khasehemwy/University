#include "addpath.h"
#include "Class.h"
#include "ui_addpath.h"

addpath::addpath(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addpath)
{
    ui->setupUi(this);
}

addpath::~addpath()
{
    delete ui;
}

void addpath::on_buttonBox_accepted()
{
    cities.addPath(ui->start->text().toStdString(),
                   ui->end->text().toStdString(),
                   ui->method->currentIndex(),
                   ui->dist->text().toInt(),
                   ui->cost->text().toInt(),
                   ui->time->text().toInt());
}

#include "mincostans.h"
#include "mincost.h"
#include "ui_mincostans.h"
#include <string>

mincostans::mincostans(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mincostans)
{
    ui->setupUi(this);
    ui->label->setStyleSheet("QLabel { font-size:12px; }");
    std::string str="";
    if(mans.size()==0) str="Not exist";
    else {
        for(int i=mans.size()-3;i>=0;i--) {
            str+=(mans[i]);
            if(i!=0) str+="->";
        }
        str += ((std::string)"\n"+"Time: "+mans[mans.size()-1]+"\nCost: "+mans[mans.size()-2]);
    }
    ui->label->setText(QString::fromStdString(str));
}

mincostans::~mincostans()
{
    delete ui;
}

#include "mindistans.h"
#include "mindist.h"
#include "ui_mindistans.h"
#include <string>

mindistans::mindistans(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mindistans)
{
    ui->setupUi(this);
    ui->label->setStyleSheet("QLabel { font-size:12px; }");
    std::string str="";
    if(mdans.size()==0) str="Not exist";
    else {
        for(int i=mdans.size()-3;i>=0;i--) {
            str+=(mdans[i]);
            if(i!=0) str+="->";
        }
        str += ((std::string)"\n"+"Time: "+mdans[mdans.size()-1]+"\nCost: "+mdans[mdans.size()-2]);
    }
    ui->label->setText(QString::fromStdString(str));
}

mindistans::~mindistans()
{
    delete ui;
}

#include "mainwindow.h"
#include "multiadd.h"
#include "singleadd.h"
#include "modifyname.h"
#include "removecity.h"
#include "addpath.h"
#include "mincost.h"
#include "mindist.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_multiadd_clicked()
{
    multiadd* add = new multiadd;
    add->show();
}

void MainWindow::on_singleadd_clicked()
{
    singleadd* add = new singleadd;
    add->show();
}

void MainWindow::on_modify_clicked()
{
    modifyname* mod = new modifyname;
    mod->show();
}

void MainWindow::on_removecity_clicked()
{
    removecity* rem = new removecity;
    rem->show();
}

void MainWindow::on_addpath_clicked()
{
    addpath* path = new addpath;
    path->show();
}

void MainWindow::on_mindist_clicked()
{
    mincost* cost = new mincost;
    cost->show();
}

void MainWindow::on_mintime_clicked()
{
    mindist* dist = new mindist;
    dist->show();
}

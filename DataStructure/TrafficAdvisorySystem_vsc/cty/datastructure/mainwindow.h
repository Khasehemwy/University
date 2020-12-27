#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_multiadd_clicked();

    void on_singleadd_clicked();

    void on_modify_clicked();

    void on_removecity_clicked();

    void on_addpath_clicked();

    void on_mindist_clicked();

    void on_mintime_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

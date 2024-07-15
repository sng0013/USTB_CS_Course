#include "swindow.h"
#include "ui_swindow.h"
#include<bank.h>
#include<QString>
#include <QMainWindow>
#include <QWidget>
#include<QApplication>
#include <QMainWindow>
#include <QWidget>
#include <QDir>
#include<userwindow.h>
#include<date.h>
#include<account.h>
Date q_1;
Date q_2;
char cmd_;
SWindow::SWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SWindow)
{
    ui->setupUi(this);
}

SWindow::~SWindow()
{
    delete ui;
}

Date SWindow::getDate_1()
{
    int d1=ui->leDay_1->text().toInt();
    int m1=ui->leMonth_1->text().toInt();
    int y1=ui->leYear_1->text().toInt();
    q_1=Date(y1, m1, d1);
    return q_1;
}
Date SWindow::getDate_2()
{
    int d2=ui->leDay_1->text().toInt();
    int m2=ui->leMonth_1->text().toInt();
    int y2=ui->leYear_1->text().toInt();
    q_2=Date(y2, m2, d2);
    return q_2;
}

char SWindow::on_btnS_clicked()
{
    return 0;
}


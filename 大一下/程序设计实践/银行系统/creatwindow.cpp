#include "creatwindow.h"
#include "ui_creatwindow.h"
#include<bank.h>
#include<QString>
#include <QMainWindow>
#include <QWidget>
#include<QApplication>
#include <QDir>
#include"bank.h"
using namespace std;
CreatWindow::CreatWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CreatWindow)
{
    ui->setupUi(this);
}

CreatWindow::~CreatWindow()
{
    delete ui;
}

void CreatWindow::on_pushButton_clicked()
{
    this->destroy();//隐藏该界面
}

QString CreatWindow::getRate()
{
    return ui->leRate->text();
}

QString CreatWindow::getCredit()
{
    return ui->leCredit->text();
}

QString CreatWindow::getFee()
{
    return ui->leFee->text();
}

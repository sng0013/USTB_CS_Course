#include "opwindow.h"
#include "ui_opwindow.h"
#include<bank.h>
#include<QString>
#include <QMainWindow>
#include <QWidget>
#include<QApplication>
#include <QDir>
OpWindow::OpWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::OpWindow)
{
    ui->setupUi(this);
}

OpWindow::~OpWindow()
{
    delete ui;
}



void OpWindow::on_cb_activated(int index)
{
    str= qobject_cast<QComboBox*>(sender())->itemText(index);
}


void OpWindow::on_pushButton_clicked()
{
    this->destroy();//隐藏该界面
}
QString OpWindow::getMoney()
{
    return ui->leMoney->text();
}

QString OpWindow::getDesc()
{
    return ui->leDesc->text();
}


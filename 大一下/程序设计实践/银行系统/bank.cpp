//这是第一个窗口的源文件
#include "bank.h"
#include "ui_bank.h"
#include"bankuser.h"
#include "userwindow.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <QLineEdit>
#include <QDebug>
#include <QMessageBox>
#include <QMainWindow>
#include<QApplication>
#include <QWidget>
#include <QDir>
using namespace std;

string Bank::Log_in_User;

Bank::Bank(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Bank)
{
    ui->setupUi(this);
    fstream users;//声明一个文件流对象users，用于文件的读写操作
    users.open("users.txt", ios_base::in);//尝试以只读模式打开名为users.txt的文件
    while(!users.eof() && users.is_open())//在一个循环中读取文件，直到到达文件末尾或文件关闭。
    {
        string id,password;
        users >> id >> password;//从文件流中提取ID和密码。
       bankUsers.push_back(new BankUser(id,password));//为每个读取的用户ID和密码创建一个新的BankUsers对象，并将其添加到bankUsers向量中。
    }
    users.close();//关闭文件流
}

Bank::~Bank()
{
    delete ui;
}

void Bank::on_btnSignin_clicked()//当注册键被按下的时候
{
    fstream users;//声明一个文件流对象users，用于文件的读写操作
    users.open("users.txt",ios_base::out|ios_base::app);//尝试以只读模式打开名为users.txt的文件
    //获取id和密码
    QString id=ui->leID->text();
    QString password=ui->lePassWord->text();

    //使用C++11的基于范围的for循环来遍历bankUsers容器。
    //auto用于自动推导iter的类型，这里iter是bankUsers容器的迭代器类型。
    //&iter表示通过引用的方式遍历容器，允许直接修改容器中的元素。
    for(auto &iter : bankUsers){
        if(iter->getID() == id.toStdString()){//如果出现重名用户
            QMessageBox::warning(this,tr("警告信息"),tr("系统中已有重名用户"));
            return;
        }
    }

    //将新输入的id和password录入到文本流中
    users<<id.toStdString()<<" "<<password.toStdString()<<endl;//向文本流写入id和password
    BankUser *bankUser=new BankUser(id.toStdString(),password.toStdString());
    bankUsers.push_back(bankUser);
    users.close();
    ui->leID->clear();
    ui->lePassWord->clear();
}


void Bank::on_btnLogin_clicked()//当登录键被按下的时候
{
    //获取id和密码
    QString id=ui->leID->text();
    QString password=ui->lePassWord->text();

    //遍历容器
    for(auto &iter : bankUsers){
        if(iter->getID() == id.toStdString()){//如果出现重名用户
            if(iter->getPassWord()==password.toStdString())
            {
                Log_in_User=iter->getID();//将登录的用户置为输入的用户名
                UserWindow *w1=new UserWindow;
                //connect(ui->btnLogin, &QPushButton::clicked, this, [&]() {
                    this->hide(); // 隐藏当前窗口

                w1->show(); // 显示另一个窗口
                //});
            }
            else {
                QMessageBox::warning(this,tr("警告信息"),tr("密码错误"));
            }
            return;
        }
    }
    QMessageBox::warning(this,tr("警告信息"),tr("系统中查无此户"));
    return;
}


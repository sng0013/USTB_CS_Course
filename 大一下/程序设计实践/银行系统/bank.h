//这是第一个窗口的头文件
#ifndef BANK_H
#define BANK_H

#include <QMainWindow>
#include<QApplication>
#include <QWidget>
#include <vector>
#include <string>
#include "bankuser.h"
#include"userwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Bank;
}
QT_END_NAMESPACE

class Bank : public QMainWindow
{
    Q_OBJECT

public:
    Bank(QWidget *parent = nullptr);
    friend class UserWindow;
    friend class CreateWindow;
    friend class OpWindow;
    friend class SWindow;
    static std::string Log_in_User;//当前登录的用户

    ~Bank();
protected:
    std::vector<BankUser*> bankUsers;
private slots:
    void on_btnSignin_clicked();

    void on_btnLogin_clicked();

private:
    Ui::Bank *ui;
};
#endif // BANK_H

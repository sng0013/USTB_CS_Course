//储蓄类的头文件
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "date.h"
#include "accumulator.h"
#include <string>
#include"account.h"

using namespace std;

class SavingsAccount: public Account
{ //储蓄账户类
private:
    Accumulator acc;	//辅助计算利息的累加器
    double rate;		//存款的年利率
public:
    SavingsAccount(const Date& date, const std::string&user,const std::string& id, double rate);//构造函数
    double getRate() const { return rate; }
    virtual void deposit(const Date& date, double amount, const std::string& desc);
    virtual void withdraw(const Date& date, double amount, const std::string& desc);
    virtual void settle(const Date& date);
};

#endif // SAVINGSACCOUNT_H

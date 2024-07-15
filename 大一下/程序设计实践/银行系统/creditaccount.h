#ifndef CREDITACCOUNT_H
#define CREDITACCOUNT_H

#include "date.h"
#include "accumulator.h"
#include <string>
#include"account.h"

using namespace std;

class CreditAccount : public Account { //信用账户类
private:
    Accumulator acc;	//辅助计算利息的累加器
    double credit;		//信用额度
    double rate;		//欠款的日利率
    double fee;			//信用卡年费

    double getDebt() const {	//获得欠款额
        double balance = getBalance();
        return (balance < 0 ? balance : 0);
    }
public:
    //构造函数
    CreditAccount(const Date& date, const string& user,const std::string& id, double credit, double rate, double fee);
    double getCredit() const { return credit; }
    double getRate() const { return rate; }
    double getFee() const { return fee; }
    double getAvailableCredit() const {	//获得可用信用
        if (getBalance() < 0)
            return credit + getBalance();
        else
            return credit;
    }
    virtual void deposit(const Date& date, double amount, const std::string& desc);
    virtual void withdraw(const Date& date, double amount, const std::string& desc);
    virtual void settle(const Date& date);
    virtual string show() const;
};

#endif // CREDITACCOUNT_H

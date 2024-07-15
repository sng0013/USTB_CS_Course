#include "savingsaccount.h"

//构造函数
SavingsAccount::SavingsAccount(const Date& date, const string& user,const string& id, double rate)
    : Account(date,user,id),  acc(date, 0),rate(rate) { }

//存钱
void SavingsAccount::deposit(const Date& date, double amount, const string& desc) {
    record(date, amount, desc);
    acc.change(date, getBalance());
}

//取钱
void SavingsAccount::withdraw(const Date& date, double amount, const string& desc) {
    if (amount > getBalance()) {
        throw AccountException(this);
    }
    else {
        record(date, -amount, desc);
        acc.change(date, getBalance());
    }
}

//计算利息
void SavingsAccount::settle(const Date& date) {
    if (date.getMonth() == 1) {	//每年的一月计算一次利息
        double interest = acc.getSum(date) * rate
                          / (date - Date(date.getYear() - 1, 1, 1));
        if (interest != 0)
            record(date, interest, " interest");
        acc.reset(date, getBalance());
    }
}

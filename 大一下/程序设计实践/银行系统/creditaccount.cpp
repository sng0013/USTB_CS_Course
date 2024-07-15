#include "creditaccount.h"
#include <iostream>
#include<string>
using namespace std;

//构造函数
CreditAccount::CreditAccount(const Date& date,const string& user, const string& id, double credit, double rate, double fee)
    : Account(date,user, id), acc(date, 0),credit(credit), rate(rate), fee(fee) { }

//取钱
void CreditAccount::deposit(const Date& date, double amount, const string& desc) {
    record(date, amount, desc);
    acc.change(date, getDebt());
}

//存钱
void CreditAccount::withdraw(const Date& date, double amount, const string& desc) {
    if (amount - getBalance() > credit) {
        // throw AccountException(this);
        throw AccountException(this);
    }
    else {
        record(date, -amount, desc);
        acc.change(date, getDebt());
    }
}

//计算利息
void CreditAccount::settle(const Date& date) {
    double interest = acc.getSum(date) * rate;
    if (interest != 0)
        record(date, interest, " interest");
    if (date.getMonth() == 1)
        record(date, -fee, " annual fee");
    acc.reset(date, getDebt());
}

//显示
string CreditAccount::show() const {
    Account::show();
    cout << "\tAvailable credit:" << getAvailableCredit();
    return 0;
}

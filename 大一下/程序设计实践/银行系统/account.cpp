#include "account.h"
#include <cmath>
#include <iostream>
#include <utility>
#include<QMultiMap>
using namespace std;
using namespace std::rel_ops;

//AccountRecord记账类的实现
AccountRecord::AccountRecord(const Date& date, const Account* account, double amount, double balance, const std::string& desc)
    : date(date), account(account), amount(amount), balance(balance), desc(desc) { }

void AccountRecord::show() const {
    date.show();
    cout << "\t#" << account->getId() << "\t" << amount << "\t" << balance << "\t" << desc << endl;
}


//Account类的实现
double Account::total = 0;
RecordMap Account::recordMap;//声明为RecordMap类型的成员变量

//构造函数
Account::Account(){};
Account::Account(const Date& date, const string& user,const string& id)
    : user(user),id(id), balance(0) {
    date.show();
    cout << "\t#" << id << " created" << endl;
}

//记账函数
void Account::record(const Date& date, double amount, const string& desc) {
    amount = floor(amount * 100 + 0.5) / 100;	//保留小数点后两位
    balance += amount;
    total += amount;
    AccountRecord record(date, this, amount, balance, desc);
    recordMap.insert(make_pair(date, record));//将一个新的键值对添加到recordMap中，其中键是date，值是record。
    record.show();
}

//输出
string Account::show() const {
    //cout << id << "\tBalance: " << balance;
    return id + "\tBalance: " + std::to_string(balance);
}

//报错
void Account::error(const string& msg) const {
    cout << "Error(#" << id << "): " << msg << endl;
}

//查询函数
// void Account::query(const Date& begin, const Date& end) {
//     if (begin <= end) {
//         RecordMap::iterator iter1 = recordMap.lower_bound(begin);//iter1是一个迭代器，它指向recordMap中第一个键值不小于begin的元素。
//         RecordMap::iterator iter2 = recordMap.upper_bound(end);
//         //在循环的每次迭代中，iter指向recordMap中的一个元素，iter->second访问这个元素的值部分，也就是AccountRecord对象。
//         for (RecordMap::iterator iter = iter1; iter != iter2; ++iter)
//             iter->second.show();
//     }
// }


//账户类的头文件
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include"date.h"
#include<string>
#include<QMultiMap>
#include<exception>
using namespace std;

class Account;

class AccountRecord {	//账目记录
private:
    Date date;				//日期
    const Account* account;	//账户
    double amount;			//金额
    double balance;			//余额
    std::string desc;		//描述
public:
    //构造函数
    AccountRecord(const Date& date, const Account* account, double amount, double balance, const std::string& desc);
    void show() const;	//输出当前记录
};

//定义用来存储账目记录的多重映射类型
typedef std::multimap<Date, AccountRecord> RecordMap;

class Account
{
private:
    std::string user;
    std::string id;	//帐号
    double balance;	//余额
    static double total; //所有账户的总金额
    static RecordMap recordMap;	//账目记录

protected:

    //记录一笔帐，date为日期，amount为金额，desc为说明
    void record(const Date& date, double amount, const std::string& desc);
    //报告错误信息
    void error(const std::string& msg) const;

public:
    Account();
    //供派生类调用的构造函数，id为账户
    Account(const Date& date, const std::string& user,const std::string& id);
    const std::string& getId() const { return id; }
    double getBalance() const { return balance; }
    static double getTotal() { return total; }
    const std::string& getUser() const { return user; }
    //存入现金，date为日期，amount为金额，desc为款项说明
    virtual void deposit(const Date& date, double amount, const std::string& desc) = 0;
    //取出现金，date为日期，amount为金额，desc为款项说明
    virtual void withdraw(const Date& date, double amount, const std::string& desc) = 0;
    //结算（计算利息、年费等），每月结算一次，date为结算日期
    virtual void settle(const Date& date) = 0;
    //显示账户信息
    virtual string show() const;
    //查询指定时间内
    static string query(Date &day1, Date &day2, string user);
    static double iaxy_uzru(Date day1, Date day2, string user); // 查询区间内收入
    static double iaxy_viiu(Date day1, Date day2, string user); // 查询区间内支出
};

//账户错误类
class AccountException :public exception
{
private:
    Account* account;
public:
    explicit AccountException(Account* account) :account(account) {};
    const char* what()const noexcept
    {
        string s1 = "Not enough money in this account:";
        string s2 = account->getId();
        string s3 = to_string(account->getBalance());
        static string s4 = s1 + s2 + "\tbalance:" + s3;
        return s4.c_str();
    }
};


#endif // ACCOUNT_H

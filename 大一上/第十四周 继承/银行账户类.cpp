#include<iostream>
using namespace std;
class Account {
public:
    Account(int accNumber, float balan) { acntNumber = accNumber, balance = balan; count++; }
    virtual void Withdrawal(float amount) = 0;// 取款
    void Deposit(float amount) { balance += amount; }// 存款
    int AccountNo() { return acntNumber; }// 账号
    void Display() { cout << acntNumber << " " << balance << endl; }// 显示信息
    static Account* First() { return pFirst; }// 获取第一个账户指针
    Account* Next() { return pNext; };// 获取下一个账户指针
    static int NumOfAccount() { return count; };//账户总数
    virtual void SetRemit(int re) {}; // 汇款
protected:
    static int count;// 用户数量
    static Account* pFirst;// 第一个账户指针
    Account* pNext;// 下一个账户指针
    int acntNumber;// 账号
    float balance;
};
int Account::count = 0;
class Savings : public Account {
public:
    Savings(int accNumber, float balan) : Account(accNumber, balan) {}
    void Withdrawal(float amount) {
        if (balance >= amount) {
            balance -= amount;
        }
        else {
            cout << "Insufficient Balance" << endl;
        }
    }
};

class Checking : public Account {
public:
    Checking(int accNumber, float balan) : Account(accNumber, balan) {}
    void Withdrawal(float amount) override {
       
        if (balance >= amount) {
            balance -= amount;
        }
        else {
            cout << acntNumber<<" Insufficient balance" << endl;
        }
    }
    void SetRemit(int re) override {
        if (re != 1) {
            balance -= 30;
        }
    }
};
int main() {
    Account* a1 = new Savings(1, 200);
    Account* a2 = new Checking(2, 500);
    a1->Display();
    a1->Withdrawal(100);
    a1->Deposit(50);
    a1->Display();
    a2->Deposit(200);
    a2->SetRemit(0);
    a2->Withdrawal(300);
    a2->Display();
    a2->Withdrawal(500);	cout << Account::NumOfAccount() << endl;
    a1->Withdrawal(50);
    a1->Display();	return 0;
}
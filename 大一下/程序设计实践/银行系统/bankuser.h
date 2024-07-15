//用户类的头文件
#ifndef BANKUSER_H
#define BANKUSER_H

#include<string>
using namespace std;
class BankUser
{
public:
    BankUser();
    BankUser(string id,string password);
    string getID();
    string getPassWord();
private:
    string id;
    string password;

};

#endif // BANKUSER_H

//用户类的源文件
#include "bankuser.h"
#include <string>
using namespace std;

BankUser::BankUser() {};

BankUser::BankUser(string _id,string _password)
{
    id=_id;
    password=_password;
}

string BankUser:: getID(){return id;}

string BankUser:: getPassWord(){return password;}

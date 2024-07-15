#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<char> a, b;
    char str, cstr;
    while (true) { // 无限循环，直到遇到换行符为止  
        cin.get(str); // 读取一个字符，包括换行符  
        if (str == '\n') { // 检查是否是换行符  
            break; // 如果是，则退出循环  
        }
        a.push_back(str); // 否则，将字符添加到vector中  
    }
    while (true) {
        cin.get(cstr);
        if (cstr == '\n') {
            break;
        }
        b.push_back(cstr);
        int num = 0;//统计子串出现次数
        
    }
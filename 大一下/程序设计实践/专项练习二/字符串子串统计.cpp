#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<char> a, b;
    char str, cstr;
    while (true) { // ����ѭ����ֱ���������з�Ϊֹ  
        cin.get(str); // ��ȡһ���ַ����������з�  
        if (str == '\n') { // ����Ƿ��ǻ��з�  
            break; // ����ǣ����˳�ѭ��  
        }
        a.push_back(str); // ���򣬽��ַ���ӵ�vector��  
    }
    while (true) {
        cin.get(cstr);
        if (cstr == '\n') {
            break;
        }
        b.push_back(cstr);
        int num = 0;//ͳ���Ӵ����ִ���
        
    }
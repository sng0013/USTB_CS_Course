#include <iostream>  
#include <string>  
using namespace std;
int main() {
    string str;
    getline(cin, str);  // ��ȡһ��������ַ���  
    char max_char = ' ';  // ��ʼ�������ĸΪ�ո�  
    for (int i = 0; i < str.size(); i++) {
        if (str[i] > max_char) {
            max_char = str[i];  // ���������ĸ  
        }
    }
    string result = str;  // ����ԭʼ�ַ���  
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == max_char) {
           int pos = i;  // ���������ĸ���ַ����е�λ��  
            result.insert(pos + 1, "(max)");  // �������ĸ�������"(max)"
        }
    }
    cout << result << endl;  // ������  
    return 0;
}
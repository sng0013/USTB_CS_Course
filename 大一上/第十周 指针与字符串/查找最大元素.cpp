#include <iostream>  
#include <string>  
using namespace std;
int main() {
    string str;
    getline(cin, str);  // 获取一行输入的字符串  
    char max_char = ' ';  // 初始化最大字母为空格  
    for (int i = 0; i < str.size(); i++) {
        if (str[i] > max_char) {
            max_char = str[i];  // 更新最大字母  
        }
    }
    string result = str;  // 复制原始字符串  
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == max_char) {
           int pos = i;  // 查找最大字母在字符串中的位置  
            result.insert(pos + 1, "(max)");  // 在最大字母后面插入"(max)"
        }
    }
    cout << result << endl;  // 输出结果  
    return 0;
}
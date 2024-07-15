#include <iostream>    
#include <string>    
#include <map>    
using namespace std;

int main() {
    // 建立映射关系    
    map<char, char> map;
    map['`'] = '`'; map['1'] = '`'; map['2'] = '1'; map['3'] = '2'; map['4'] = '3'; map['5'] = '4'; map['6'] = '5'; map['7'] = '6'; map['8'] = '7'; map['9'] = '8'; map['0'] = '9';
    map['-'] = '0'; map['='] = '-'; 
    map['Q'] = 'Q'; map['W'] = 'Q'; map['E'] = 'W'; map['R'] = 'E'; map['T'] = 'R'; map['Y'] = 'T'; map['U'] = 'Y';
    map['I'] = 'U'; map['O'] = 'I'; map['P'] = 'O'; map['['] = 'P'; map[']'] = '[';
    map['A'] = 'A'; map['S'] = 'A'; map['D'] = 'S'; map['F'] = 'D'; map['G'] = 'F'; map['H'] = 'G'; map['J'] = 'H'; map['K'] = 'J'; map['L'] = 'K';
    map[';'] = 'L'; map[' '] = '; ';
    map['Z'] = 'Z'; map['X'] = 'Z'; map['C'] = 'X'; map['V'] = 'C'; map['B'] = 'V'; map['N'] = 'B'; map['M'] = 'N'; map[','] = 'M'; map['.'] = ','; map['/'] = '.';
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            cout << ' ';
        }
        else {
            // 查找映射关系并输出    
            cout << map[s[i]];
        }
    }
    return 0;
}
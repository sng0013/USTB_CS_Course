#include <iostream>  
#include <string>  
using namespace std;  
  
char encryptChar(char c) {  
    if (isalpha(c)) {  
        if (isupper(c)) {  
            return ((c - 'A' + 3) % 26 + 'A');  
        } else {  
            return ((c - 'a' + 3) % 26 + 'a');  
        }  
    } else {  
        return c;  
    }  
}  
  
int main() {  
    string s;  
    getline(cin, s);  
    for (int i = 0; i < s.length(); i++) {  
        s[i] = encryptChar(s[i]);  
    }  
    cout << s << endl;  
    return 0;  
}

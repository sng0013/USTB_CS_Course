#include <iostream>  
#include <string>  

int main() {
    std::string str1, str2;
    std::cin >> str1 >> str2;

    if (str1 == str2) {
        std::cout << "YES" << std::endl;
    }
    else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}
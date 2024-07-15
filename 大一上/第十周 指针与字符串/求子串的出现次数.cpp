#include <iostream>  
#include <string>  

int countOccurrences(const std::string& a, const std::string& bd) {
    int count = 0;
    size_t pos = 0;
    while ((pos = a.find(bd, pos)) != std::string::npos) {
        ++count;
        pos += bd.length();
    }
    return count;
}

int main() {
    std::string a;
    std::cin >> a;
    std::string bd = "bd";
    int result = countOccurrences(a, bd);
    std::cout << result << std::endl;
    return 0;
}
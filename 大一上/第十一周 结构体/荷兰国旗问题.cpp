#include <iostream>
#include <cstring>

int main() {
    // 读取输入的字符串
    std::string input;
    //std::cout << "请输入由 Red、White 和 Blue 构成的字符串数组，以空格分隔:\n";
    std::getline(std::cin, input);

    // 将输入字符串复制到字符数组中
    char str[1000];
    strcpy(str, input.c_str());

    // 使用 strtok 分割字符串
    char* token = strtok(str, " ");

    // 分别存储 Red、White、Blue 的数量
    int redCount = 0, whiteCount = 0, blueCount = 0;

    // 统计各个颜色的数量
    while (token != nullptr) {
        if (strcmp(token, "Red") == 0) {
            redCount++;
        }
        else if (strcmp(token, "White") == 0) {
            whiteCount++;
        }
        else if (strcmp(token, "Blue") == 0) {
            blueCount++;
        }

        // 继续分割，传入 NULL
        token = strtok(nullptr, " ");
    }

    // 输出排序后的结果
    for (int i = 0; i < redCount; i++) {
        std::cout << "Red ";
    }
    for (int i = 0; i < whiteCount; i++) {
        std::cout << "White ";
    }
    for (int i = 0; i < blueCount; i++) {
        std::cout << "Blue ";
    }

    std::cout << std::endl;

    return 0;
}

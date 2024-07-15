#include <iostream>
#include <cstring>

int main() {
    // ��ȡ������ַ���
    std::string input;
    //std::cout << "�������� Red��White �� Blue ���ɵ��ַ������飬�Կո�ָ�:\n";
    std::getline(std::cin, input);

    // �������ַ������Ƶ��ַ�������
    char str[1000];
    strcpy(str, input.c_str());

    // ʹ�� strtok �ָ��ַ���
    char* token = strtok(str, " ");

    // �ֱ�洢 Red��White��Blue ������
    int redCount = 0, whiteCount = 0, blueCount = 0;

    // ͳ�Ƹ�����ɫ������
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

        // �����ָ���� NULL
        token = strtok(nullptr, " ");
    }

    // ��������Ľ��
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

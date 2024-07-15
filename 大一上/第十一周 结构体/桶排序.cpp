#include <iostream>

// ����Ͱ������
#define BUCKET_COUNT 100

// Ͱ������
void bucketSort(int arr[], int n) {
    // ����1: ����Ͱ������ʼ��ÿ��Ͱ�ļ���Ϊ0
    int buckets[BUCKET_COUNT] = { 0 };

    // ����2: ��Ԫ�ط����Ӧ��Ͱ�У�Ͱ�м�¼Ԫ�ظ���;
    // ������˵������ʹ������Ԫ�ص�ֵ arr[i]��ΪͰ��������������ӦͰ�ļ���ֵ��1��
    for (int i = 0; i < n; i++) {
        buckets[arr[i]]++;
    }

    // ����3: �����������������
    for (int i = 0; i < BUCKET_COUNT; i++) {
        // ���Ͱ��Ԫ��
        while (buckets[i] > 0) {
            std::cout << i << " ";
            buckets[i]--;
        }
    }
}

int main() {
    // ��ȡ���������
    int arr[10];
    for (int i = 0; i < 10; i++) {
        std::cin >> arr[i];
    }

    // ����4: ����Ͱ������
    bucketSort(arr, 10);

    return 0;
}

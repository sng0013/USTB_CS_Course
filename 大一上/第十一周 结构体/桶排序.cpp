#include <iostream>

// 定义桶的数量
#define BUCKET_COUNT 100

// 桶排序函数
void bucketSort(int arr[], int n) {
    // 步骤1: 创建桶，并初始化每个桶的计数为0
    int buckets[BUCKET_COUNT] = { 0 };

    // 步骤2: 将元素放入对应的桶中，桶中记录元素个数;
    // 具体来说，我们使用数组元素的值 arr[i]作为桶的索引，并将对应桶的计数值加1。
    for (int i = 0; i < n; i++) {
        buckets[arr[i]]++;
    }

    // 步骤3: 依次输出排序后的数列
    for (int i = 0; i < BUCKET_COUNT; i++) {
        // 输出桶中元素
        while (buckets[i] > 0) {
            std::cout << i << " ";
            buckets[i]--;
        }
    }
}

int main() {
    // 读取输入的数列
    int arr[10];
    for (int i = 0; i < 10; i++) {
        std::cin >> arr[i];
    }

    // 步骤4: 调用桶排序函数
    bucketSort(arr, 10);

    return 0;
}

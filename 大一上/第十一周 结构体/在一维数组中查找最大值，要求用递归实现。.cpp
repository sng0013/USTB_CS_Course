#include<iostream>
using namespace std;
int Max(int arr[], int low, int high) {
    // 基本情况：当区间只有一个元素时，返回该元素
    if (low == high) {
        return arr[low];
    }
    // 计算中间位置
    int mid = (low + high) / 2;
    // 在左半区间查找最大值
    int maxL = Max(arr, low, mid);
    // 在右半区间查找最大值
    int maxR = Max(arr, mid + 1, high);
    // 返回左右区间最大值中的较大者
    return max(maxL, maxR);
}

int main() {
    int n;
    cin >> n;
    int *arr=new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // 调用递归函数查找数组中的最大值
    int result = Max(arr, 0, n - 1);

    cout << result << endl;

    return 0;
}

#include<iostream>
using namespace std;
int Max(int arr[], int low, int high) {
    // ���������������ֻ��һ��Ԫ��ʱ�����ظ�Ԫ��
    if (low == high) {
        return arr[low];
    }
    // �����м�λ��
    int mid = (low + high) / 2;
    // ���������������ֵ
    int maxL = Max(arr, low, mid);
    // ���Ұ�����������ֵ
    int maxR = Max(arr, mid + 1, high);
    // ���������������ֵ�еĽϴ���
    return max(maxL, maxR);
}

int main() {
    int n;
    cin >> n;
    int *arr=new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    // ���õݹ麯�����������е����ֵ
    int result = Max(arr, 0, n - 1);

    cout << result << endl;

    return 0;
}

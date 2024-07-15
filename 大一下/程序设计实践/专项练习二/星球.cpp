#include<iostream>  
#include<algorithm>  
#include<sstream>  
using namespace std;

//绝对值函数
int PositiveNumber(int t) {
    return (t < 0) ? -t : t;
}

//计算距离
int Location(int x, int y, int z, int* arr, int n) {
    int distance = 0;
    for (int i = 0; i < n; i++) {
        int _x = x - arr[3*i];
        int _y = y - arr[3*i + 1];
        int _z = z - arr[3*i + 2];
        distance += PositiveNumber(_x) + PositiveNumber(_y) + PositiveNumber(_z);
    }
    return distance;
}

int main() {
    int N;
    //cout << "input N:" << endl;
    cin >> N;
    int* arr = new int[3 * N];
    int* dis = new int[N];
    string line;
    getline(cin, line);//实现输入空格
    for (int i = 0; i < N; i++) {
        //cout << "input position:" << endl;

        getline(cin, line);//实现输入空格
        //处理字符串（忽略空格符）
        istringstream iss(line);
        int x, y, z;
        iss >> x >> y >> z;

        arr[3 * i] = x;
        arr[3 * i + 1] = y;
        arr[3 * i + 2] = z;
    }
    //按序当中心星球
    for (int t = 0; t < N; t++) {
        dis[t] = Location(arr[3*t], arr[3*t + 1], arr[3*t + 2], arr, N);
    }
    //找距离最小
    sort(dis, dis + N);
    cout << dis[0] << endl;
    delete[] arr;
    delete[] dis;
    return 0;
}
#include <iostream>
#include <list>

using namespace std;

// 定义函数找出猴子大王的编号
int findKing(int m, int n) {
    list<int> monkeys;

    // 初始化猴子编号列表
    for (int i = 1; i <= m; ++i) {
        monkeys.push_back(i);
    }

    auto it = monkeys.begin();
    while (monkeys.size() > 1) {
        // 计算下一个出圈的猴子的位置
        for (int i = 0; i < n - 1; ++i) {
            ++it;
            if (it == monkeys.end()) {
                it = monkeys.begin();
            }
        }

        // 移除出圈的猴子
        it = monkeys.erase(it);
        if (it == monkeys.end()) {
            it = monkeys.begin();
        }
    }

    return monkeys.front();
}

int main() {
    int m, n;

    // 输入猴子的个数 m 和出圈基数 n
    
    cin >> m;
   
    cin >> n;

    // 调用函数并输出结果
    int king = findKing(m, n);
    cout << king << endl;

    return 0;
}



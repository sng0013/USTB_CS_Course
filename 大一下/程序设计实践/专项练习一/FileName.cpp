#include <iostream>
#include <list>

using namespace std;

// ���庯���ҳ����Ӵ����ı��
int findKing(int m, int n) {
    list<int> monkeys;

    // ��ʼ�����ӱ���б�
    for (int i = 1; i <= m; ++i) {
        monkeys.push_back(i);
    }

    auto it = monkeys.begin();
    while (monkeys.size() > 1) {
        // ������һ����Ȧ�ĺ��ӵ�λ��
        for (int i = 0; i < n - 1; ++i) {
            ++it;
            if (it == monkeys.end()) {
                it = monkeys.begin();
            }
        }

        // �Ƴ���Ȧ�ĺ���
        it = monkeys.erase(it);
        if (it == monkeys.end()) {
            it = monkeys.begin();
        }
    }

    return monkeys.front();
}

int main() {
    int m, n;

    // ������ӵĸ��� m �ͳ�Ȧ���� n
    
    cin >> m;
   
    cin >> n;

    // ���ú�����������
    int king = findKing(m, n);
    cout << king << endl;

    return 0;
}



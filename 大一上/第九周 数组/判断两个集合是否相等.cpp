#include <iostream>  
#include <unordered_set>  
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    unordered_set<int> set1, set2;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        set1.insert(x);
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        set2.insert(x);
    }
    if (set1 == set2) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }
    return 0;
}

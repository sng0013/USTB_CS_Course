#include<iostream>
using namespace std;
int compute(int n, int k)
{
        if (n < k) {
            return 0;
        }
        else if (n == k || k == 0) {
            return 1;
        }
        else {
            return compute(n - 1, k - 1) + compute(n - 1, k);
        }
}
int main()
{
	int m, n;
	cin >> m >> n;
	cout << compute(m, n);
	return 0;
}
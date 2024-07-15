#include<iostream>
using namespace std;
int main()
{
	int n, i, a0, a1;
	cin >> n;
	a0 = 0; a1 = 1;
	if (n <= 2) { cout << n - 1 << endl; }
	else {
		for (i = 2; i <= n / 2; i++)
		{
			a0 = a0 + a1;
			a1 = a1 + a0;
		}
		if (n % 2 != 0) { cout << a0+ a1 << endl; }
		else { cout << a1 << endl; }
	}
}
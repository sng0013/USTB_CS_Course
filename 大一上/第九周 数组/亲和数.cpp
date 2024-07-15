#include<iostream>
using namespace std;
int sum(int);
int main()
{
	int n, m;
	cin >> n >> m;
	int a = sum(n);
	int b = sum(m);
	if (a == m && b == n)cout << "YES" << endl;
	else cout << "NO" << endl;
}
int sum(int x)
{
	int sum=0;
	for (int i = 1; i < x; i++)
	{
		if (x % i == 0) { sum += i; }
	}
	return sum;
}
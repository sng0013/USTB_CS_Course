#include<iostream>
using namespace std;
long f(int n)
{
	if (n == 1) { return 1; }
	else return n*f(n - 1);
}
int main()
{
	int n;
	cout << "n=";
	cin >> n;
	cout << "n!=" << f(n);
}
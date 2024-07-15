#include<iostream>
using namespace std;
int f(int, int);
int main()
{
	int a, b;
	cout << "a,b=";
	cin >> a >> b;
	if (a < b) { int t = a; a = b; b = t; }
	int y = f(a, b);
	cout << y;
	return 0;
}
int f(int x, int y)
{
	if (y == 0) { return x; }
	else f(y, x % y);
}
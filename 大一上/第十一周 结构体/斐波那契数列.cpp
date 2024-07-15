#include<iostream>
using namespace std;
long Fibonacci(int n)
{
	if (n == 0)
		return 0;
	else {
		if (n == 1)
		{
			return 1;
		}
		else return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}
int main()
{
	int n;
	cout<<"n=";
	cin >> n;
	cout << "f(n)=" << Fibonacci(n-1);
	return 0;
}
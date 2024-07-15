#include<iostream>
using namespace std;
int main()
{
	long n;
	cin >> n;
	int i;
	if(n==1) cout << "NO" << endl;
	else
	{
		for (i = 2; i <= n; i++)
		{
			if (n % i == 0) break;
		}
		if (i > n - 1) { cout << "YES" << endl; }
		else { cout << "NO" << endl; }
	}
}
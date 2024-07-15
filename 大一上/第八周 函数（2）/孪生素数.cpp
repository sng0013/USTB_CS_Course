#include<iostream>
#include<cmath>
using namespace std;
int is_prime(int x)
{
	for (int i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0) { return false; }
	}
	return true;
}
int main()
{
	int i, m;
	cin >> m;
	for(i=m-2;i>=3;i--)
		if(is_prime(i)&&is_prime(i+2))
		{
			cout << i << " " << i + 2;
			break;
		}
	return 0;
}
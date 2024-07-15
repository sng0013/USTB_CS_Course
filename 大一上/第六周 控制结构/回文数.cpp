#include<iostream>
using namespace std;
int main()
{
	int num;
	cin >> num;
	if(num>=10000&&num<100000)
	{
		int a = num / 10000;
		int b = (num % 10000) / 1000;
		int c = (num %100) /10;
		int d = num % 10;
		if (a == d && b == c) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
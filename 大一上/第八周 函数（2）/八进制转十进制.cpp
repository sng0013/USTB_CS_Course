#include<iostream>
using namespace std;
int main()
{
	int n; //n为八进制数
	cin >> n;
	int sum = 0;//sum为十进制数
	int x = 0;//x为每次更新后的数的个位数
	for (int i = 0; n != 0; i++)
	{
		x = n % 10;
		for (int y=i;y > 0; y--)
		{
			x *= 8;
		}
		sum += x;
		n = n / 10;
	}
	cout << sum << endl;
}
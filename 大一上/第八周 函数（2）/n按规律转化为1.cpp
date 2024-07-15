#include<iostream>
using namespace std;
int cal_step1(int);
int cal_step2(int);
int main()
{
	int n;
	cin >> n;
	if(n==1)
	{
		cout << 1 << endl;
		cout << 1 << endl;
	}
	else
	{
		int i = 0;
		for (i; n != 1; i++)
		{
			if (n % 2 == 0) { n = cal_step1(n); }
			else { n = cal_step2(n); }
			cout << n<<" ";
		}
		cout << endl;
		cout << i << endl;

	}
}
int cal_step1(int x)
{
	x = x / 2;
	return x;
}
int cal_step2(int y)
{
	y = 3*y+1;
	return y;
}
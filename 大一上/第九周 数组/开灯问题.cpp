#include<iostream>
using namespace std;
int main()
{   //创建动态数组
	int n;
	cin >> n;
	int* light = new int[n];
	for (int i = 0; i < n; i++)
	{
		 light[i]=-1;
	}
	//输入多少人进行开关操作；
	int k;
	cin >> k;
	//进行开关操作
	int t;
	for (int i = 1; i <= k; i++)
	{
		for (t=1; t <= n; t++)
		{
			if (t % i == 0) { light[t-1] *= (-1); }
		}
	}
	//输出开着的灯
	for (t= 0; t< n; t++)
	{
		if (light[t] == 1) { cout << t+1 << " "; }
	}
	delete[]light;
	return 0;

}
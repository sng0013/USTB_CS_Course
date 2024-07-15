#include<iostream>
using namespace std;
int individual_sal(int);
int main()
{   //创建动态数组，输入n个员工的工资
	int n;
	cin >> n;
	int* sal = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> sal[i];
	}
	//循环计算每个员工需要多少张人民币，再计算总数
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int x = individual_sal(sal[i]);
		sum += x;
	}
	cout << sum;
	//返还动态空间
	delete[]sal;
	return 0;
}
int individual_sal(int a)
{
	int a1 = a / 100;//计算多少张100元
	int x1 = a - a1 * 100;
	int a2 = x1 / 50;//计算多少张50元
	int x2 = x1 - a2 * 50;
	int a3 = x2 / 10;//计算多少张10元
	int x3 = x2 - a3 * 10;
	int a4 = x3 / 5;//计算多少张5元
	int x4 = x3 - a4 * 5;
	int a5 = x4 / 2;//计算多少张2元
	int a6 = x4 - a5 * 2;//计算多少张一元
	return (a1 + a2 + a3 + a4 + a5 + a6);
}
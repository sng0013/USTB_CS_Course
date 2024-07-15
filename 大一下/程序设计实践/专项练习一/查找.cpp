#include<iostream>
using namespace std;

int FindNumber(int*, int,int);
int FindPlace(int*, int,int);

//主函数：实现输入数据和调用函数的功能
int main()
{
	int n;
	cout << "请输入要查找的数据总数：";
	cin >> n;
	int* a = new int[n];
	cout << "请输入一组数据："<<endl;
	for (int t = 0; t < n; t++)
	{
		cin >> a[t];
	}
	cout << "请输入要查找的数" << endl;
	int x = 0;
	cin >> x;
	int y = FindNumber(a,n,x);
	FindPlace(a,n,y);
	return 0;
}

//实现遍历查找的功能
int FindNumber(int* a,int n,int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x) { cout << "找到" << a[i]<<", "; return a[i]; }
	}
	cout << "不存在"<<endl;
	return 0;
}

//实现遍历查找位置的功能
int FindPlace(int* a, int n, int y)
{

	for (int i = 0; i < n; i++)
	{
		if (a[i] == y) { cout << "位置是" << i + 1; return 0; }
	}
	cout << "不存在";
	return 0;
}
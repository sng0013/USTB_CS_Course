#include<iostream>
using namespace std;

int FindNumber(int*, int,int);
int FindPlace(int*, int,int);

//��������ʵ���������ݺ͵��ú����Ĺ���
int main()
{
	int n;
	cout << "������Ҫ���ҵ�����������";
	cin >> n;
	int* a = new int[n];
	cout << "������һ�����ݣ�"<<endl;
	for (int t = 0; t < n; t++)
	{
		cin >> a[t];
	}
	cout << "������Ҫ���ҵ���" << endl;
	int x = 0;
	cin >> x;
	int y = FindNumber(a,n,x);
	FindPlace(a,n,y);
	return 0;
}

//ʵ�ֱ������ҵĹ���
int FindNumber(int* a,int n,int x)
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == x) { cout << "�ҵ�" << a[i]<<", "; return a[i]; }
	}
	cout << "������"<<endl;
	return 0;
}

//ʵ�ֱ�������λ�õĹ���
int FindPlace(int* a, int n, int y)
{

	for (int i = 0; i < n; i++)
	{
		if (a[i] == y) { cout << "λ����" << i + 1; return 0; }
	}
	cout << "������";
	return 0;
}
#include<iostream>
using namespace std;
int individual_sal(int);
int main()
{   //������̬���飬����n��Ա���Ĺ���
	int n;
	cin >> n;
	int* sal = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> sal[i];
	}
	//ѭ������ÿ��Ա����Ҫ����������ң��ټ�������
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int x = individual_sal(sal[i]);
		sum += x;
	}
	cout << sum;
	//������̬�ռ�
	delete[]sal;
	return 0;
}
int individual_sal(int a)
{
	int a1 = a / 100;//���������100Ԫ
	int x1 = a - a1 * 100;
	int a2 = x1 / 50;//���������50Ԫ
	int x2 = x1 - a2 * 50;
	int a3 = x2 / 10;//���������10Ԫ
	int x3 = x2 - a3 * 10;
	int a4 = x3 / 5;//���������5Ԫ
	int x4 = x3 - a4 * 5;
	int a5 = x4 / 2;//���������2Ԫ
	int a6 = x4 - a5 * 2;//���������һԪ
	return (a1 + a2 + a3 + a4 + a5 + a6);
}
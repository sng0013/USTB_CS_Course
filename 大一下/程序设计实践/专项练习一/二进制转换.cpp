#include<iostream>
#include<cmath>
using namespace std;
double PositiveNumber(int* a);
double NegativeNumber(int* a);
int* PlusFunction(int* a);
int main()
{
	//����һ��16λ�����ʾ�Ķ���������
	int a[16];
	for (int i = 0; i < 16; i++)
	{
		cin >> a[i]; 
	}
	if (a[0] = 0) { cout<<PositiveNumber(a); }
	else { cout<<NegativeNumber(a); }
	return 0;
}
//�������Ķ�����ת��
double PositiveNumber(int* a)
{
	double t = 0;
	for (int i = 0; i < 16; i++)
	{
		t += a[i] * pow(2, 16 - i);
	}
	return t;
}
//�������Ķ�����ת��
double NegativeNumber(int* a)
{
	double t = 0;
	for (int i = 0; i < 16; i++)
	{
		if (a[i] == 0) { a[i] = 1; }
		else a[i] = 0;
	}
	PlusFunction(a);
	return PositiveNumber(a);
}
int* PlusFunction(int* a)
{
	a[15] += 1;
	for (int i = 15; i >= 0; i--)
	{
		if (a[i] == 2) {
			a[i] = 0;
			a[i - 1] += 1;
		}
	}
	return a;
}
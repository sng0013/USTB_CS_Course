#include<iostream>
using namespace std;
int main()
{   //������̬����
	int n;
	cin >> n;
	int* light = new int[n];
	for (int i = 0; i < n; i++)
	{
		 light[i]=-1;
	}
	//��������˽��п��ز�����
	int k;
	cin >> k;
	//���п��ز���
	int t;
	for (int i = 1; i <= k; i++)
	{
		for (t=1; t <= n; t++)
		{
			if (t % i == 0) { light[t-1] *= (-1); }
		}
	}
	//������ŵĵ�
	for (t= 0; t< n; t++)
	{
		if (light[t] == 1) { cout << t+1 << " "; }
	}
	delete[]light;
	return 0;

}
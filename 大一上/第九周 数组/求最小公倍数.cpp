#include<iostream>
using namespace std;
int gcd(int a, int b) { // �����Լ�� (�������������Լ���������н�С�����������Ĳ�����Լ����) 
	if (a == 0) return b;
	return gcd(b % a, a);
}

int lcm(int a, int b) { // ����С������  
	return a * b / gcd(a, b);
}
int main()
{
	int n;
	cin >> n;
	int a[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> a[i];
	}
		int ans = lcm(lcm(a[0], a[1]), a[2]); // ��������������С�����������������������С������  
		cout << ans << endl;
		return 0;
}
#include<iostream>
using namespace std;
int main()
{
	int n; //nΪ�˽�����
	cin >> n;
	int sum = 0;//sumΪʮ������
	int x = 0;//xΪÿ�θ��º�����ĸ�λ��
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
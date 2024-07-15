#include<iostream>
using namespace std;
int f(int,int);
int main()
{
	int y;
	cin >> y;
	int N;
	cin >> N;
	y = f(y,N);
	cout << y - 1 << endl;
	
}
int f(int m,int n)
{
	for (; n > 0; m++)
	{
		if ((m % 4 == 0 && m % 100 != 0) || (m % 400 == 0))
		{
			n--;
		}
	}
	return m;
	
}
#include<iostream>
using namespace std;
int main()
{
	int n;
	int sum = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int s = i * i * i;
		sum += s;
	}
	cout << sum << endl;
}
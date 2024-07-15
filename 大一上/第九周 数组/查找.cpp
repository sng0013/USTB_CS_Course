#include<iostream>
using namespace std;
int main()
{
	int a[8];
	int num = 0;
	for (int i = 0; i <= 7; i++)
	{
		cin >> a[i];
	}
	cin >> num;
	bool x=0;
	for (int i = 0; i <=7; i++)
	{
		if (num == a[i]) { cout << i+1 << endl; x = 1; break; }
	}
	if (x == 0)
	{
		cout << "cannot find" << endl;
	}
	return 0;
}
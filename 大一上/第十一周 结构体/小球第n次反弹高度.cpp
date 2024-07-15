#include<iostream>
using namespace std;
int main()
{
    double height=100;
	int n = 0;
	cin >> n;
	for (int i = 0; i != n; i++)
	{
		height /= 2;
	}
	cout << height << endl;
	return 0;
}
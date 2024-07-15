#include<iostream>
using namespace std;
int main()
{
	char ch[50];
	cin >> ch;
	bool t = 1;
	for (int i = 0; i < 50; i++)
	{
		if (ch[i] == 's') { cout << i << endl; t = 0; break; }
	}
	if (t == 1) { cout << -1 << endl; }
	return 0;
}
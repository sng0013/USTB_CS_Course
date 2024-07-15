#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	cin >> str;
	int a = str.size();
	bool t = 1;
	for(int i=1;i<=a;i++)
	{
		if (str[i] == str[i + 1]) {
			cout << "YES" << endl; t = 0; break;
		}
	}
	if (t == 1) { cout << "NO" << endl; }
}

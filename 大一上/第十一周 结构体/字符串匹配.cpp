#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str, cstr;
	cin >> str >> cstr;
	int X = str.find(cstr);
	if (X == -1) { cout << "can't find" << endl; }
	else cout << "find at " << X + 1 << endl;
	return 0;
}
#include<iostream>
using namespace std;
int main()
{
	char c;
	cin >> c;
	if ((c <= 'z' && c >= 'a')&&(c<='Z'&&c>='A')) { cout << "char" << endl; }
	else {
		if (c <= '9' && c >= '0') { cout << "digit" << endl; }
		else { cout << "other" << endl; }
	}
}
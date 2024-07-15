#include<iostream>
using namespace std;
int main()
{
	int a;
	cin >> a;
	if (a < 0) cout << "illegal input" << endl;
	else { 
		if (a < 5) { cout << a << endl; }
		else {
			if (a < 15) { cout << a + 6 << endl; }
			else { cout << a - 6 << endl; }
		}
	}
}
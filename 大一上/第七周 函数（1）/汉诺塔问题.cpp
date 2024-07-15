#include<iostream>
using namespace std;
void move(int n, char a, char b, char c)
{
	if (n == 1)
		cout << a << " to " << c << endl;
	else{
		move(n - 1, a, c, b);
		cout << a << " to " << c << endl;
		move(n - 1, b, a, c);
	}
}
int main()
{
	int m;
	cin >> m;
	move(m, 'A', 'B', 'C');
}
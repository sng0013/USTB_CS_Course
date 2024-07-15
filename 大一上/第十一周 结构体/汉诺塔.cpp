#include<iostream>
using namespace std;
void Move(int n, char a, char b, char c)
{
	 static int t = 0;
	if (n == 1)
	{
		t += 1;
		cout << a << "-->" << c << " " << t << endl;
	}
	else {
		Move(n - 1, a, c, b);
		t += 1;
		cout << a << "-->" << c << " " << t<< endl;
		Move(n - 1, b, a, c);
	}
}
int main()
{
	int m;
	cout << "Input the number of disks:" << endl;
	cin >> m;
	Move(m, 'A', 'B', 'C');
}
#include<iostream>
using namespace std;
void sort1(int& x, int& y, int& z)
{
	int t;
	if(x<y)
	{
		t = x, x = y,y=t;
	}
	if(x<z)
	{	
		t = x, x = z, z = t;
	}
	if(y<z)
	{
		t = y, y = z, z = t;
	}
}
void sort2(int* x, int* y, int* z)
{
	int t;
	if (*x < *y)
	{
		t =*x, *x = *y, *y = t;
	}
	if (*x < *z)
	{
		t = *x, *x = *z, *z = t;
	}
	if (*y < *z)
	{
		t = *y, *y = *z, *z = t;
	}
}
int  main()
{
	int  a = 3, b = 2, c = 1;
	int* s1 = &a, * s2 = &b, * s3 = &c;
	cin >> a >> b >> c;
	sort1(a, b, c);
	cout << a << '  ' << b << '  ' << c << endl;
	cin >> a >> b >> c;
	sort2(s1, s2, s3);
	cout << a << '  ' << b << '  ' << c << endl;
	return  0;
}
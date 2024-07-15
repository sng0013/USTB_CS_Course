#include<iostream>
using namespace std;
double mod(int,int);
double mod(double, double);
double mod(int x, int y)
{
	return x%y;
}
double mod(double x, double y)
{
	int a = x / 1;
	int b = y / 1;
	if (a > 0 && b > 0) {
		if (x > a + 0.5)
		{
			x = a + 1;
		}
		else { x = a; }
		if (y > b + 0.5)
		{
			y = b + 1;
		}
		else { y = b; }
		return((int)x % (int)y);
	} 
	if (a < 0 && b < 0) {
		if (x > a - 0.5)
		{
			x = a;
		}
		else { x = a-1; }
		if (y > b - 0.5)
		{
			y = b ;
		}
		else { y = b-1; }
		return((int)x % (int)y);
	}
}
int main()
{
	cout << "mod(8,3)=" << mod(8, 3) << endl;
	cout << "mod(8.2,3.6)=" << mod(8.2, 3.6) << endl;
	cout << "mod(-8.2,-2.6)=" << mod(-8.2, -2.6) << endl;
	return  0;
}

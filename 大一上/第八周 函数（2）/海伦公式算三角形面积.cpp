#include<iostream>
#include<cmath>
using namespace std;
double area(double, double b = 5.0, double c = 6.0);
int main()
{
	double a = 4.0, b = 5.0, c = 6.0;
	cout << area(a) << endl;
	cout << area(a, b) << endl;
	cout << area(a, b, c) << endl;
}
double area(double a, double b, double c)
{
	double s = (a + b + c) / 2;
	double area = sqrt(s * (s - a) * (s - b) * (s - c));
	return area;
}
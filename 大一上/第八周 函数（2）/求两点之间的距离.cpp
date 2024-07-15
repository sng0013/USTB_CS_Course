#include<iostream>
#include<cmath>
using namespace std;
int distance(int a, int b, int c, int d)
{
	int distance = sqrt((a - c) * (a - c) + (b - d) * (b - d));
	return distance;
}
double distance(double a, double b, double c, double d)
{
	double distance = sqrt((a - c) * (a - c) + (b - d) * (b - d));
	return distance;
}
int main()
{
	int a1, b1, a2, b2;
	cin >> a1 >> b1 >> a2 >> b2;
	float c1, d1, c2, d2;
	cin >> c1 >> d1 >> c2 >> d2;
	cout << distance(a1, b1, a2, b2) << endl;
	cout << distance(c1, d1, c2, d2) << endl;
}
#include<iostream>
using namespace std;
class Circle
{
public:
	Circle(int, int, int);
	float getArea();
	int getQuadrant();
private:
	int x;
	int y;
	int r;
};
Circle::Circle(int pX, int pY, int pR)
{
	x = pX;
	y = pY;
	r = pR;
}
float Circle::getArea()
{
	const double PI = 3.14;
	float area = PI * r * r;
	return area;
}
int Circle::getQuadrant()
{
	if (x > 0 && y > 0) return 1;
	if (x < 0 && y > 0) return 2;
	if (x < 0 && y < 0) return 3;
	if (x > 0 && y < 0) return 4;
}
int main()
{
	Circle c1(20, 30, 5);
	Circle c2(20, 40, 30);
	cout << "The area of the first circle." << c1.getArea() << endl;
	cout << "The quadrant of the first circle." << c1.getQuadrant() << endl;
	cout << "The area of the second circle." << c2.getArea() << endl;
	cout << "The quadrant of the second cicle." << c2.getQuadrant() << endl;
    return 0;
}
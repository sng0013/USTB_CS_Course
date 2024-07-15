#include<iostream>
using namespace std;
const double PI = 3.14159167;
class Shape
{public:
	virtual void getarea()const = 0;
	virtual void getgrith()const = 0;
};
class Circle :public Shape
{
public:
    void getradius(int radius) { r = radius; }
	void getarea()const { cout << PI * r * r<<endl; }
	void getgrith()const { cout << 2 * PI * r<<endl; }
private:
	int r;
};
class Rectangle :public Shape
{
public:
	void getradius(int aa, int bb) { a = aa, b = bb; }
	void getarea()const { cout << a * b<<endl; }
	void getgrith()const { cout << 2 * (a + b)<<endl; }
private:
	int a, b;
};
void fun1(Shape& n)
{
	n.getarea();
	n.getgrith();
}
int main()
{
	int a,b,r;
	cin >> a >> b >> r;
	Rectangle rectangle;
	rectangle.getradius(a, b);
	fun1(rectangle); 
	Circle circle;
	circle.getradius(r);
	fun1(circle);
	return 0;
}
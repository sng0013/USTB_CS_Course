#include<iostream>
using namespace std;
class Point
{
public:
	Point(int x=0, int y=0) { X = x, Y = y;  }
	virtual void print(){ cout << "This is Point" << endl; }
	~Point() {};
protected:
	int X, Y;
};
class Point3d:public Point
{public:
	Point3d(int x=0, int y=0, int z=0) :Point(x, y) { Z = z;  }
	void print(){ cout << "This is 3D Point" << endl; }
	~Point3d() {};
private:
	int Z;
};
int main()
{
	Point point;
	Point* p = NULL;
	Point3d pp;
	p = &point;
	p->print();
	p = &pp;
	p->print();
	p = NULL;
	return 0;
}
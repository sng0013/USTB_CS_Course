#include<iostream>
#include<string>
using namespace std;
const double PI = 3.14158889;
class Circle
{
public:
	Circle(int r) { radius = r; }
	virtual void getarea() { cout<< PI * radius * radius<<endl; }
	virtual ~Circle() {};
private:
	int radius;
};
class Table
{public:
	Table(int h) { height = h; }
	virtual void getheight() { cout << height << endl; }
	virtual ~Table() {};
private:
	int height;
};
class Roundtable:public Circle,public Table
{
public:
	Roundtable(int r,int h, string c): Circle(r),Table(h){ colour = c; }
	void getcolour() { cout << colour << endl; }
	~Roundtable() {};
private:
	string colour;
};
int main()
{
	int x, y;
	string z;
	cin >> x >> y >> z;
	Roundtable roundtable(x, y, z);
	roundtable.getarea();
	roundtable.getheight();
	roundtable.getcolour();
}
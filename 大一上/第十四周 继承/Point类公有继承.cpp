#include<iostream>
using namespace std;
class Point
{
public:
	void InitP(float xx = 0, float yy = 0) { X = xx; Y = yy; }
	void Move(float xOff, float yOff) { X += xOff; Y += yOff; }
	float GetX() { return X; }
	float GetY() { return Y; }
private:
	float X, Y;
};
class Rectangle :public Point
{
public:
	void wid_he(int L, int W) { l = L; w = W; }
	float Getl() { return l; }
	float Getw() { return w; }
private:
	int l, w;
};
int main()
{
	int x, y, l, w;
	float xOff, yOff;
	cin >> x >> y >> l >> w >> xOff >> yOff;
	Rectangle r1;
	r1.InitP(x, y);
	r1.Move(xOff, yOff);
	r1.wid_he(l, w);
	cout << r1.GetX() <<" "<< r1.GetY()<<" "
		<< r1.Getl() <<" "<< r1.Getw() << endl;
	return 0;

}
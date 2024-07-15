#include <iostream>  
using namespace std;

class Point
{
public:
    Point(int xx = 0, int yy = 0) { X = xx; Y = yy; } //���캯��  
    Point(const Point& p); //���ƹ��캯��  
    int GetX() { return X; }
    int GetY() { return Y; }
private:
    int X, Y;
};

Point::Point(const Point& p)
{
    X = p.X;
    Y = p.Y;
}

void fun1(Point p)
{
    cout << p.GetX() << endl;
}

Point fun2()
{
    Point A(1, 2);
    return A;
}

int main()
{
    Point A(4, 5); //����һ��point��Ķ���A���ò�����4,5����ʼ����  
    Point B = A; //����һ��point��Ķ���B����A��ʼ��B��  
    cout << B.GetX() << endl; //���B.GetX()��  
    fun1(B); //����fun1()������B��Ϊfun1��ʵ�Ρ�  
    B = fun2(); //ִ��B=fun2()��  
    cout << B.GetX() << endl; //���B.GetX()��  
    return 0;
}
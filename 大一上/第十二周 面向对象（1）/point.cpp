#include <iostream>  
using namespace std;

class Point
{
public:
    Point(int xx = 0, int yy = 0) { X = xx; Y = yy; } //构造函数  
    Point(const Point& p); //复制构造函数  
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
    Point A(4, 5); //定义一个point类的对象A，用参数（4,5）初始化。  
    Point B = A; //定义一个point类的对象B，用A初始化B。  
    cout << B.GetX() << endl; //输出B.GetX()。  
    fun1(B); //调用fun1()，对象B作为fun1的实参。  
    B = fun2(); //执行B=fun2()。  
    cout << B.GetX() << endl; //输出B.GetX()。  
    return 0;
}
#include<iostream>
using namespace std;
class my_base 
{
protected:
  int a, b;
public:
  my_base(int x, int y){ a = x; b = y;}
  virtual void show()   //¶¨ÒåÐéº¯Êýshow()
  { cout << a << " " << b << endl;}
};
class my_class:public my_base
{
private:
	int c;
public:
	my_class(int aa,int bb,int cc):my_base(aa,bb) { c = cc; }
	void show() { cout << c << endl; }
};
int main()
{
	int a, b, c;
	cin >> a>>b>> c;
	my_class m(a, b, c);
	m.my_base::show();
	m.show();
}
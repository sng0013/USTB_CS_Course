#include<iostream>
using namespace std;
class rectangle
{
public:
	int l, w;
	void area() {
		int s = l * w;
		cout << s << endl;
	}
};
int main()
{
	rectangle x;
	cin >> x.l >> x.w;
	x.area();
}
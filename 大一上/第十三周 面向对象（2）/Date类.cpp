#include<iostream>
using namespace std;
class Date
{
public:
	void set_date(int, int, int);
	void disp_date();
private:
	int year, month, day;
};
void Date::set_date(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}
void Date::disp_date()
{
	cout << year << "." << month << "." << day << endl;
}
int main()
{
	Date date;
	int x, y, z;
	cin >> x >> y >> z;
	date.set_date(x, y, z);
	date.disp_date();
}
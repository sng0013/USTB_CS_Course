#include<iostream>
using namespace std;
int main()
{
	int year, month, day;
	int a = 0;
	cin >> year >> month >> day;
	if (month == 2 && day == 29) cout << "-"<<'1' << endl;
	else {
		for (int i = 1; i <= 18; i++)
		{
			bool b =( (year % 100 != 0) && (year % 4 == 0) )|| (year % 400 == 0);
			if (b == 1) { a++; }
			year++;
		}
		bool t = (((year+18) % 100 != 0) && ((year+18) % 4 == 0)) || ((year+18) % 400 == 0);
		if (month > 2 && t == 1) { a++; }
		int days;
		days = (18 - a) * 365 + 366 * a;
		cout << days << endl;
	}
}
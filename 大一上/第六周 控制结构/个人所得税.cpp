#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	double _money,tax, money;
	cin >> _money;
	if(_money>0)
	{
		if (_money <= 1000)
		{
			tax = 0;
			money = _money;
			cout << "tax=" <<  setprecision(2)<<fixed<<tax<< "," <<" "<<"money=" << setprecision(2) << fixed << money << endl;
		}
		else {
			if (_money <= 2000)
			{
				tax = (_money - 1000) * 0.05;
				money = _money - tax;
				cout << "tax=" << setprecision(2) << fixed << tax << "," <<" "<<"money=" << setprecision(2) << fixed << money << endl;
			}
			else if(_money<=3000)
			     {
				  tax = (_money - 2000) * 0.1+50;
				  money = _money - tax;
				  cout << "tax=" << setprecision(2) << fixed << tax << "," <<" "<<"money=" << setprecision(2) << fixed << money << endl;
			      }
			      else if(_money<=6000)
				{
					tax = (_money - 3000) * 0.15+150;
					money = _money - tax;
					cout << "tax=" << setprecision(2) << fixed << tax << "," <<" "<<"money=" << setprecision(2) << fixed << money << endl;
				}
				  else {
				tax = (_money - 6000) * 0.20+600;
				money = _money - tax;
				cout << "tax=" << setprecision(2) << fixed << tax << "," <<" "<<"money=" << setprecision(2) << fixed << money << endl;
			}
		}
	}

}
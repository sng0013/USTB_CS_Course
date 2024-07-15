#include<iostream>
using namespace std;
int main()
{
	int m;
	cin >> m;
	if (m < 10 && m>1)
	{
		int total;
		if(m%2==0)
		{
			total = (m / 2) * (m - 1) * (m - 1) +  (m - 1) * m;
		}
		else { total = (m - 1) * m + ((m - 1) / 2) * (m - 1) * (m - 1); }
		cout << total << endl;
	}
	

}
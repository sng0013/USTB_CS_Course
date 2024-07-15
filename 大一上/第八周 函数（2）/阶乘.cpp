#include<iostream>
using namespace std;
int f(int);
int main()
{
	int n;
	cin >> n;
	cout << n<<endl;
	cout << n << "!=" << f(n) << endl;
}
 int f(int t)
{
	 if (t == 0) return 1;
	 else
		 return t * f(t - 1);
}
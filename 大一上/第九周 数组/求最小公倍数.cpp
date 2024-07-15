#include<iostream>
using namespace std;
int gcd(int a, int b) { // 求最大公约数 (两个整数的最大公约数等于其中较小的数和两数的差的最大公约数。) 
	if (a == 0) return b;
	return gcd(b % a, a);
}

int lcm(int a, int b) { // 求最小公倍数  
	return a * b / gcd(a, b);
}
int main()
{
	int n;
	cin >> n;
	int a[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> a[i];
	}
		int ans = lcm(lcm(a[0], a[1]), a[2]); // 先求两个数的最小公倍数，再与第三个数求最小公倍数  
		cout << ans << endl;
		return 0;
}
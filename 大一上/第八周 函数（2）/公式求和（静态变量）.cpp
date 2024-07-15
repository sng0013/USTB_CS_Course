#include<iostream>
#include<cstring>
using namespace std;
float factorial(int n)
{
	static int product = 1;
	static int sum=1;
	if (product == n)
		 product =sum;
	else {
		product++;
		sum *= product;
		float factorial(n);
	}
	return product;
}
int main()
{
	int n = 1;
	float sum = 0, temp;
	do {
		temp = (n+1)/factorial(n);
		n++;
		sum += temp;
	} while (temp > 1e-6);
	cout << sum << endl;
	return 0;
}
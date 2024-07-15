#include<iostream>
using namespace std;
int f(int& n)
{
	n = 4;
	return 3;
}
int main()
{
	int i = 0, j;
	j = f(i);
	cout << i << " " << j;
	return 0;
}
#include<iostream>
using namespace std;
int search(int, int, int);
int main()
{
	int a, b, c;
	for(a=123;a<329;a++)
	{
		b = a * 2;
		c = a * 3;
		int t = search(a,b,c);
		if (t == 1) { cout << a << " " << b << " " << c << " " << endl; }
		
	}
}
int search(int a, int b, int c)
{
	int a1 = a /100;int a2 = (a%100)/10;int a3 = a % 10;
	int b1 = b/100;int b2 = (b%100)/10;int b3 = b % 10; 
	int c1 = c/100;int c2 = (c%100)/10;int c3 = c % 10;
	int arr[9] = { a1,a2,a3,b1,b2,b3,c1,c2,c3 };
	for(int i=0;i<9;i++)
	{
		if (arr[i] == 0) { return false; }
	}
	for (int i = 0; i < 9; i++)
	{
		for (int n = i+1; n <=8; n++)
		{
			if (arr[i] == arr[n]) {return false;}
		}
	}
	return true;
}

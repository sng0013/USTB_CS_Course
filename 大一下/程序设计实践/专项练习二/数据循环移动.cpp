#include<iostream>
using namespace std; 
int* move(int* a, int n = 10)
{
	int *b=new int[10];
	for (int i = 0; i < 10; i++)
	{
		if (i < 7) { b[i + 3] = a[i]; }
		else { b[i - 7] = a[i]; }
	}
	return b;
}
int main()
{
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}
	int *brr = move(arr);
	for (int i = 0; i < 10; i++)
	{
		cout << *(brr + i) << " ";
	}
	delete[]brr;
	return 0;
}
#include<iostream>
using namespace std;
int mysort(int* a, int n)
{
	a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[n];
	}
	int size = sizeof(a) / sizeof(a[0]);
	for (int pass = 1; pass <= size - 1; pass++)
	{
		int work = 1;
		for (int i = 0; i < size - 1 - pass; i++)
		{
			if (a[i] > a[i + 1])
			{
				int temp = a[i];
				a[i] = a[i + 1];
				a[i + 1] = temp;
				work = 0;
			}
		}
		if(work) break;
	}
	return *a;
}
int main()
{
	int i, n;
	int* a = 0;
	cin >> n;
	mysort(a, n);
	for (i = 0; i < n; i++)
	{
		cout << a[i] << " ";
		cout << endl;
	}
	delete[]a;
	return 0;
}
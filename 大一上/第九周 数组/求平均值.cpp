#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int* Num = new int[n];
	int sum = 0;
	for(int i=0;i<n;++i)
	{
		cin >> Num[i];
		sum += Num[i];
	}
	double average =(double) sum / n;
	cout << average;
	delete[]Num;
	Num = NULL;
	
}
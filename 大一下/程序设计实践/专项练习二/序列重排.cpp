#include<iostream>
#include<algorithm>
using namespace std;
int Func(int*A, int nSize)
{
	sort(A, A + nSize, greater<int>());//对数组元素进行降序排列
	for (int i = 0; i <nSize; i++)
	{
		if (A[i] == 0) { return i; }
	}
}
int main()
{
	int nSize=0,number;
	int A[4000] ;
	char ch;
	while (cin>>number)
	{
		A[nSize]=number;
		nSize++;
		cin.get(ch);
		if (ch != ' ')
			break;
	}
	int m= Func(A,nSize);
	for (int i = 0; i <nSize; i++)
	{
		cout << A[i] << ' ';
	}
	cout << endl << m;
	return 0;
}
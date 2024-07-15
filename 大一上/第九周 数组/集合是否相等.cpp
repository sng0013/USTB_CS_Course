#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n, m;
	//创建集合（动态数组）A；
	cin >> n;
	int* A = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> A[i];
	}
	//创建集合（动态数组）B；
	cin >> m;
	int* B = new int[m];
	for (int i = 0; i < m; ++i)
	{
		cin >> B[i];
	}
	//对数组大小进行排序
	sort(A, A + n);
	sort(B, B + m);
	//去重
	int x = n;
	int y = m;
	for (int i = 0; i < n; i++)
	{
		if ( A[i] == A[ i + 1]) { x = i; break; }
	}
	for (int i = 0; i < m; i++)
	{
		if (B[i] == B[i + 1]) { y = i; break; }
	}
	//比较两个数组是否相同
	if (x != y) { cout << "no" << endl; }
	else {
		bool t = 1;
		for (int i = 0; i < x; i++) {
			if (A[i] != B[i]) { cout << "no" << endl; t = 0; break; }
		}
		cout << "yes" << endl;
	}
	//释放空间
	delete[]A;
	delete[]B;
	return 0;
}
	



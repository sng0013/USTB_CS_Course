#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n, m;
	//�������ϣ���̬���飩A��
	cin >> n;
	int* A = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> A[i];
	}
	//�������ϣ���̬���飩B��
	cin >> m;
	int* B = new int[m];
	for (int i = 0; i < m; ++i)
	{
		cin >> B[i];
	}
	//�������С��������
	sort(A, A + n);
	sort(B, B + m);
	//ȥ��
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
	//�Ƚ����������Ƿ���ͬ
	if (x != y) { cout << "no" << endl; }
	else {
		bool t = 1;
		for (int i = 0; i < x; i++) {
			if (A[i] != B[i]) { cout << "no" << endl; t = 0; break; }
		}
		cout << "yes" << endl;
	}
	//�ͷſռ�
	delete[]A;
	delete[]B;
	return 0;
}
	



#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char ch[20];
	cin >> ch;
	//�󴮳�
	int a = strlen(ch);
	//����Ϊż�����ַ�
	if (a % 2 == 0) {
		for (int i = 0; i < (a/2); i++)
		{
			int temp = ch[i];
			ch[i] = ch[a-i-1];
			ch[a - i - 1] = temp;
		}
	}
	//����Ϊ�������ַ�
	else {
		for (int i = 0; i < ((a -1)/ 2); i++)
		{
			int temp = ch[i];
			ch[i] = ch[a - i - 1];
			ch[a - i - 1] = temp;
		}
	}
	cout << ch << endl;
	return 0;
}
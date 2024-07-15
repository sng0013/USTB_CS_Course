#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	char ch[20];
	cin >> ch;
	//求串长
	int a = strlen(ch);
	//假如为偶数个字符
	if (a % 2 == 0) {
		for (int i = 0; i < (a/2); i++)
		{
			int temp = ch[i];
			ch[i] = ch[a-i-1];
			ch[a - i - 1] = temp;
		}
	}
	//假如为奇数个字符
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
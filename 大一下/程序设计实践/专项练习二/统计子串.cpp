#include<iostream>
#include<cstring>
using namespace std;
int CountCstr(char* str, char* cstr)
{
	int count = 0;
	int lenStr = strlen(str);
	int lenCstr = strlen(cstr);
	while (*str)
	{
		if (strncmp(str, cstr, lenCstr) == 0) {
			count++;
			str ++;
		}
		else { str++; }
	}
	return count;
}
int main()
{
	char str[4000],cstr[4000];
	cin >> str;
	cin >> cstr;
	cout<<CountCstr(str, cstr);
}
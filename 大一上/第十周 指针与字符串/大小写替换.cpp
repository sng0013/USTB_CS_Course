#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	char ch[20];
	cin.get(ch, 20);
	cin >> ch;
	for (int i = 0; i < 20; i++)
	{
		if ((ch[i] >= 65 && ch[i] <= 90) || (ch[i] >= 97 && ch[i] <= 122)) 
		{
			if (ch[i] >= 65 && ch[i] <= 90) 
			{
				ch[i] = ch[i] + 32;
			}
			else { ch[i] = ch[i] - 32; }
		}
	}
	cout << ch;
}
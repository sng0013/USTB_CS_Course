#include<iostream>
using namespace std;
struct
{
	int x;
	char* y;
}; s[2] = { {1,"hello"},{2,"world"} }, * p = s;
int main()
{
	cout << *(++p->y) << " ";
	cout << p->x;
	return 0;
}
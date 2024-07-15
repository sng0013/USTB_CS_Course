
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	string str ;
	cin >> str;
	str.erase(remove(str.begin(), str.end(), 'T'), str.end()); //在容器中, 删除[begin,end)之间的所有值等于'T'的值.
	cout << str << endl;
	return 0;
}

#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	string str ;
	cin >> str;
	str.erase(remove(str.begin(), str.end(), 'T'), str.end()); //��������, ɾ��[begin,end)֮�������ֵ����'T'��ֵ.
	cout << str << endl;
	return 0;
}
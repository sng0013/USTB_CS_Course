#include<iostream>
using namespace std;
class Student
{public:
	char Name[10];
	int Age;
	int No;
	void print()
	{
		cout << "Name:" << Name << " Age:" << Age << " No:" << No << endl;
	}
};
int main()
{
	Student sb;
	cin >> sb.Name >> sb.Age >> sb.No;
	sb.print();
}
#include<iostream>
using namespace std;
class Student
{
private:
	char* name;
	int age;
	char* no;
public:
	Student(char* name, int age, char* no);
	~Student() {};
	char* getName() { return name; }
	int getAge() { return age; }
	char* getNo() { return no; }
};

Student::Student(char* na, int ag, char* n)
{
	age = ag;
	name = new char[strlen(na) + 1];
	if (name != 0)strcpy_s(name, strlen(na) + 1, na);
	no = new char[strlen(n) + 1];
	if (no != 0)strcpy_s(no, strlen(n) + 1, n);
}
int main()
{
	char name[20];
	int age;
	char no[20];
	cin >> name >> age >> no;
	Student stu(name, age, no);
	cout << "Name:" << stu.getName() << " Age:" << stu.getAge() << " No:" << stu.getNo() << "\n";
	return 0;
}
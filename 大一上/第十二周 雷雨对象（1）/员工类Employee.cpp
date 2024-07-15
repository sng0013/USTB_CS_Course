#include<iostream>
#include<cstring>
using namespace std;
class Employee
{
public:
	Employee(int pId, char* pName, char pSex, char* pPosition);
	~Employee();
	void printEmployee();
	void setSex(char pSex);
private:
	int id;
	char* name;
	char sex;
	char* position;
};
Employee::Employee(int pId, char* pName, char pSex, char* pPosition) 
{
	id = pId;
	name = new char[strlen(pName) + 1];
	if (name != 0)strcpy_s(name, strlen(pName) + 1, pName);
	sex = pSex;
	position = new char[strlen(pPosition) + 1];
	if (position != 0)strcpy_s(position, strlen(pPosition) + 1, pPosition);
}
Employee::~Employee()
{
	delete[]name;
	name = NULL;
	delete[]position;
	position = 0;
}
inline void Employee::printEmployee()
{
	cout << "id" << id << ", " << name << ","
		<< "sex: " << sex << ", " << "position: " << position << endl;
}
void Employee::setSex(char pSex='M')
{
	sex = pSex;
}
int main()
{
	Employee emp(1001, "zhangxiao", "F", "manager");
	emp.printEmployee();
	emp.setSex();
	emp.printEmployee();
	return 0;
}

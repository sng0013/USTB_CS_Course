#include<iostream>
#include<cstring>
using namespace std;
class Course
{
public:
	Course();
	Course(int, char*, int, char*);
	void setCourse(int, char*, int ,char*);
	void printCourse();
private:
	int id;
	char* name;
	int hours;
	char* teacherInCharge;
};
Course::Course()
{
	cout << "Constructed without Parameters." << endl;
}
Course::Course(int pId, char* pName, int pHours, char* pTeacherInCharge)
{
	id = pId;
	name = new char[strlen(pName) + 1];
	if (name != 0) strcpy_s(name, strlen(pName) + 1, pName);
	hours = pHours;
	teacherInCharge = new char[strlen(pTeacherInCharge) + 1];
	if (teacherInCharge != 0) strcpy_s(teacherInCharge, strlen(pTeacherInCharge) + 1, pTeacherInCharge);
	cout << "Constructed with Parameters." << endl;
}
void Course::setCourse(int pId, char* pName, int pHours, char* pTeacherInCharge)
{
	id = pId;
	name = new char[strlen(pName) + 1];
	if (name != 0) strcpy_s(name, strlen(pName) + 1, pName);
	hours = pHours;
	teacherInCharge = new char[strlen(pTeacherInCharge) + 1];
	if (teacherInCharge != 0) strcpy_s(teacherInCharge, strlen(pTeacherInCharge) + 1, pTeacherInCharge);
	cout << "Constructed with Parameters." << endl;
}
Course::~Course()
{
	delete[]name;
	delete[]teacherInCharge;
	cout << "Deconstructed." << endl;
}
void Course::printCourse()
{
	cout << "id: " << id << ", "
		<< "hours:" << hours << ", "
		<< "teacherInCharge: " << teacherInCharge
		<< endl;
}
int main()
{
	Course c[3];
	c[0].setCourse(1001, "Math", 56, "zhangsan");
	c[1].setCourse(1002, "C++", 64, "lisi");
	c[2].setCourse(1003, "History", 48, "wangwu");
	Course* pCourse = new Course(1004, "DaataStructure", 72, "zhaoliu");
	c[0].printCourse();
	c[1].printCourse();
	c[2].printCourse();
	pCourse->printCourse();
	delete pCourse;
	return 0;
}
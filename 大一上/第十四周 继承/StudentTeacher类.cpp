#include<iostream>
using namespace std;

//Person类，有姓名和电话。
class Person
{
public:
	Person(const char* Name, const char* Tele) {
		name = new char[strlen(Name) + 1];
		strcpy_s(name, strlen(Name) + 1, Name);
		tele = new char[strlen(Tele) + 1];
		strcpy_s(tele, strlen(Tele) + 1, Tele);
	}
	virtual void GetName() { cout << name<<endl; }
	virtual void GetTele() { cout << tele<<endl; }
	virtual ~Person() {};
protected:
	char* name;
	char* tele;
};
//student类，继承Person类，有专业。
class Student:virtual public Person
{
public:
	Student(const char* Name, const char* Tele, const char* Major) :Person(Name,Tele){
		major = new char[strlen(Major) + 1];
		strcpy_s(major, strlen(Major) + 1, Major);
	}
	virtual void GetMajor() { cout << major<<endl; }
    ~Student() {};
protected:
	char* major;
};

//Teacher类，继承Person类，有教授的课程。
class Teacher :virtual public Person
{
public:
	Teacher(const char* Name, const char* Tele, const char* Course) :Person(Name, Tele) {
		course = new char[strlen(Course) + 1];
		strcpy_s(course, strlen(Course) + 1, Course);
	}
	virtual void GetCourse() { cout << course<<endl; }
	~Teacher() {};
protected:
	char *course;
};

//StudentTeacher类，继承Student和Teacher类。
class StudentTeacher:public Student,public Teacher
{
public:
	StudentTeacher(const char* Name, const char* Tele, const char* Major, const char* Course) :Person(Name, Tele), Student(Major), Teacher(Course) {};
	void GetName() { cout << name << endl; }
    void GetTele() { cout << tele << endl; }
	void GetMajor() { cout << major << endl; }
	void GetCourse() { cout << course << endl; }
};
int main()
{
	char* p1, p2, p3, p4;
	cin >> p1 >> p2 >> p3 >> p4;
	StudentTeacher st();
}


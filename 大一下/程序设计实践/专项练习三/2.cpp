#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Major
{
public:
	int ID;
	string _name;
	static int _count;
	void getMajor(string Name) { _name = Name; ++_count; ID = _count; }
	~Major() {};
};
int Major::_count = -1;

class Student:public Major
{
public:
	int id;
	string name;
	static int count;
	int major_ID;
	void originalId() { major_ID = -1; }
	void getStudent(string Name) { name = Name; ++count; id = count; }
	void getMajor(int major_id) { major_ID = major_id; }
	void deleteMajor() { major_ID = -1; }
	~Student() {};
};
int Student::count = -1;


int main()
{
	char ch;
	vector<Student> a(10);
	vector<Major> b(10);
	string name;
	string _name;
	int i = 0,t=0;
	int x=0, y=0, z=0;
	while (cin >> ch)
	{
		//创建一个学生
		if (ch == 's') {
			cin >> name;
			a[i].getStudent(name);
			a[i].originalId();
			i++;
			continue;
		}
		//创建一个专业
		if (ch == 'm') {
			cin >> _name;
			b[t].getMajor(_name);
			t++;
			continue;
		}
		//让某个学生加入某个专业
		if (ch == 'a') {
			cin >> x >> y;
			a[x].getMajor(y);
			continue;
		}
		//让某个学生退出某个专业
		if (ch == 'd') {
			cin >> x >> y;
			a[x].deleteMajor();
			continue;
		}
		//让某个学生从专业A转到专业B
		if (ch == 'v') {
			cin >>y >> x >> z;
			a[x].getMajor(z);
			continue;
		}
		//显示所有学生的信息
		if (ch == 'n') {
			for (int m = 0; m < i; m++)
			{
				cout << a[m].id << '-' << a[m].name << ' ';
			}
			cout << endl;
			continue;
		}
		//显示所有专业的信息
		if (ch == 'l') {
			for (int n = 0; n <t; n++)
			{
				cout <<"Major "<<b[n].ID << '-' << b[n]._name << ": ";
				for (int m = 0; m <i; m++) {
					if (a[m].major_ID == b[n].ID)
					{
						cout << a[m].id << '-' << a[m].name << ' ';
					}
				}
				cout << endl;
			}
			continue;
		}
		if (ch == 'e')
			break;
	}
	return 0;
}

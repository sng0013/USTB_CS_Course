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
		//����һ��ѧ��
		if (ch == 's') {
			cin >> name;
			a[i].getStudent(name);
			a[i].originalId();
			i++;
			continue;
		}
		//����һ��רҵ
		if (ch == 'm') {
			cin >> _name;
			b[t].getMajor(_name);
			t++;
			continue;
		}
		//��ĳ��ѧ������ĳ��רҵ
		if (ch == 'a') {
			cin >> x >> y;
			a[x].getMajor(y);
			continue;
		}
		//��ĳ��ѧ���˳�ĳ��רҵ
		if (ch == 'd') {
			cin >> x >> y;
			a[x].deleteMajor();
			continue;
		}
		//��ĳ��ѧ����רҵAת��רҵB
		if (ch == 'v') {
			cin >>y >> x >> z;
			a[x].getMajor(z);
			continue;
		}
		//��ʾ����ѧ������Ϣ
		if (ch == 'n') {
			for (int m = 0; m < i; m++)
			{
				cout << a[m].id << '-' << a[m].name << ' ';
			}
			cout << endl;
			continue;
		}
		//��ʾ����רҵ����Ϣ
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

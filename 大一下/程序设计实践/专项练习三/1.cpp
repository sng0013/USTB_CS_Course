#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Course
{
public:
	int n;
	string name;
	int prerequisites_n;
	~Course() {};
};
void display(vector<Course>c,int t)
{
	
	if (c[t].prerequisites_n == -1) { cout << endl; return; }
	else {
		for (int m=t; m >= 0; m--){
			if (c[m].n == c[t].prerequisites_n){
				cout << c[m].name << ' ';
				t = m;
				break;
			}
		}
		display(c, t);
	}
}
int main()
{
	char ch;
	string name;
	int pre_n,i=-1;
	vector<Course>a(10);
	while (cin >> ch)
	{
		if (ch == 'c') {
			i++;
			cin >> name >> pre_n;
			a[i].n = i;
			a[i].name = name;
			a[i].prerequisites_n = pre_n;
			continue;
		}
		if (ch == 's') {
			for (int t = 0; t <= i; t++)
			{
				cout << "Course " << a[t].n << '-' << a[t].name << " has prerequisites: ";
				if (a[t].prerequisites_n == -1) { cout << "none" << endl; }
				else{ display(a, t); }
			}
		}
		if (ch == 'e') { break; }
	}
	return 0;
}

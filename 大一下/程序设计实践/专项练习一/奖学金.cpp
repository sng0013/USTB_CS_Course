#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;

class Student;
int Academician(int score, int paperNumber);
int MayFouth(int score, int point);
int Exellent(int score);
int Western(int score, bool IsWeststudent);
int Contribution(int score, bool IsClasscadre);
void Scholarship(Student s);

//Student类
class Student
{
public:
	string name;//姓名
	int score;//平均成绩
	int classPoint;//班级评议成绩
	bool IsClasscadre;//是否为班级干部
	bool IsWeststudent;//是否为西部学生
	int paperNumber;//发表论文总数
	int money;//奖学金总数

};
//计算奖学金总数
void Scholarship(Student s)
{
    s.money = 0;
	s.money += Academician(s.score, s.paperNumber);
	s.money += MayFouth(s.score, s.classPoint);
	s.money += Exellent(s.score);
	s.money = Western(s.score, s.IsWeststudent);
	s.money += Contribution(s.score, s.IsClasscadre);
}
//院士奖学金
int Academician(int score, int paperNumber)
{
	if (score > 80 && paperNumber >= 1) { return 8000; }
	else return 0;
}
//五四奖学金
int MayFouth(int score, int point)
{
	if (score > 80 && point >= 1) { return 4000; }
	else return 0;
}
//成绩优秀奖
int Exellent(int score)
{
	if (score > 90) { return 2000; }
	else return 0;
}
//西部奖学金
int Western(int score, bool IsWeststudent)
{
	if (score > 85 && (IsWeststudent == 1)) { return 1000; }
	else return 0;
}
//班级贡献奖
int Contribution(int score, bool IsClasscadre)
{
	if (score > 85 && (IsClasscadre == 1)) { return 850; }
	else return 0;
}


int main()
{
	int N;
	cout << "Please input N(1<=N<=100):";
	cin >> N;
	cout << "please input the students' information:";
	Student* a = new Student[N];
	for (int i = 0; i < N; i++)
	{
		cin >> a[i].name
			>> a[i].score
			>> a[i].classPoint
			>> a[i].IsClasscadre
			>> a[i].IsWeststudent
			>> a[i].paperNumber;
	}
	int* b = new int[N];
	int sum=0;
	for (int i = 0; i < N; i++)
	{
		Scholarship(a[i]);
		b[i] = a[i].money;
		sum += b[i];
	}
	sort(b, b + N);
	for (int i = 0; i < N; i++)
	{
		if (a[i].money == b[N - 1]) {
			cout << a[i].name<<endl
				<< a[i].money<<endl
				<< sum;
		}
	}
	return 0;
}
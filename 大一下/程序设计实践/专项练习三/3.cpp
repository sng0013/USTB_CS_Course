#include<iostream>
#include<string>
using namespace std;

static int i = 0;

class Point2D
{
public:
	
	Point2D() {};
	void getPoint2D(int _x, int _y) { x = _x, y = _y; }
	~Point2D() {};
	int x, y;
};

class Creature
{
public:
	Creature() {};
	void displayPoint2D() { cout << "(" << point.x << ", " << point.y << ')'<<endl; }
	~Creature() {};
	string name;
	int ID;
	Point2D point;
};

void creatCreature(Creature* creature)
{
	int x = 0, y = 0;
	cin >> creature[i].name >> x >> y;
	creature[i].ID = i;
	creature[i].point.getPoint2D(x, y);
	//cout << "生成一个新人物，名字为" << creature[i].name << ",位置为";
	//creature[i].displayPoint2D();
	//cout<< endl;
	i++;
	return;
}

void displayCreature(Creature* creature)
{
	for (int t = 0; t < i; t++)
	{
		cout << "No. " << t << " creature " << creature[t].name << " is at ";
		creature[t].displayPoint2D();
		cout << endl;
	}
	cout << endl; // 添加换行符
	return;
}

void moveCreature(Creature* creature)
{
	int t = 0,x=0,y=0;
	cin >> t >> x >> y;
	creature[t].point.x = x;
	creature[t].point.y = y;
	//cout << "移动" << i << "号人物到";
	//creature[t].displayPoint2D();
	cout << endl;
	return;
}

void displaySingle(Creature* creature, int m)
{
	//cout << "显示" << m << "号人物的信息" << endl;
	cout << "No. " << m << " creature " << creature[m].name << " is at ";
	creature[m].displayPoint2D();
	//cout << "显示" << m << "号人物的信息" << endl;
	return;
}

int main()
{
	Creature creature[10];
	char ch='e';
	while (cin >> ch)
	{
		if (ch == 'n') 
		{creatCreature(creature);continue;}
		if (ch == 'a')
		{ 
			//cout << "显示所有人物" << endl; 
		displayCreature(creature); continue; 
		}
		if (ch == 'm')
		{ moveCreature(creature); continue; }
		if (ch == 's') 
		{ int m = 0; cin >> m; displaySingle(creature, m); }
		if (ch == 'e') 
		{ 
			//cout << "退出程序" << endl; 
		break; 
		}
	}
	return 0;
}




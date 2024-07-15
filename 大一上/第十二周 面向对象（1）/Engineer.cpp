#include<iostream>
#include<cstring>
using namespace std;
//Engineer类的定义
class Engineer
{public:
	int Id;
	const char *Name;
	const char *Position;
    Engineer(int x, const char* y, const char* z) { Id = x; Name = y; Position = z; }
	void setEngineer(int ID, const char *name,  const char* position) { Id = ID; Name = name; Position = position; }
	void printEngineer();
};
void Engineer::printEngineer()
{
	cout << "id: " << Id << ",name:" << Name << ",position" << Position << endl;
}int  main()
{
    Engineer  e[4];
    e[0].setEngineer(1001, "wanghan", "lecture");
    e[1].setEngineer(1002, "zhangqing", "lecture");
    e[2].setEngineer(1003, "zhaojing", "professor");
    e[3].setEngineer(1004, "yaolin", "professor");
    Engineer* pE1 = new  Engineer(1005, "fangwei", "professor");
    Engineer* pE2 = new  Engineer(1006, "huangling", "professor");
    e[0].printEngineer();
    e[1].printEngineer();
    e[2].printEngineer();
    e[3].printEngineer();
    pE1->printEngineer();
    pE2->printEngineer();
    delete  pE1, pE2;
    return  0;
}
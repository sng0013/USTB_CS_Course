#include<iostream>
using namespace std;
const int MAXLENGTH = 10;
class CSet
{
public:
	CSet(int a[], int size);//用数组a的前size个元素初始化集合
    CSet(const CSet& set) {};
	bool AddElem(int e);
	CSet Intersection(CSet& set);
	void Print();
private:
	int data[MAXLENGTH];
	int size;
};
CSet::CSet(int a[],int size)
{
    for (int i = 0; i < size; i++)
    {
        data[i] = a[i];
    }
}
bool CSet::AddElem(int e)
{
    for (int i = 0; i < size; i++) {
        if (data[i] == e) {
            return false;
        }
    }
    if (size < MAXLENGTH) {
        data[size++] = e;
        return true;
    }
    else {
        return false;
    }
}
void  CSet::Print()
{
    int  i;
    for (i = 0; i < size; i++)
        cout << data[i] << "  ";
    cout << endl;
}

int  main()
{
    int  a[8] = { 2,3,4,5,6,7,8,9 };
    int  b[10] = { 1,3,4,6,8,9,11,14,16,18 };
    int  x, y;
    cin >> x >> y;
    CSet  s1(a, x), s2(b, y);
    s1.Print();
    s2.Print();
    s1.AddElem(11);
    s1.Print();
    (s1.Intersection(s2)).Print();
    return  0;
}
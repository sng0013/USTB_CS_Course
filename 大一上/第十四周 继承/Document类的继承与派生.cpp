#include<iostream>
#include<string>
using namespace std;
class Document
{
public:
	Document(string name) { Name = name; }
	virtual void PrintNameOf() { cout << Name << endl; }
	virtual ~Document() {};
protected:
	string Name;
};
class Book:public Document
{
public:
	Book(string name1, long pagecount):Document(name1) {  PageCount = pagecount; }
	void PrintNameOf() { cout << Name << endl; }
private:
	long PageCount;
};
int main()
{
	string s1, s2;
	long p;
	cin >> s1 >> s2 >> p;
	Book book(s2, p);
	cout << "Name of book: ";
	book.PrintNameOf();
	return 0;
}
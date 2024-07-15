#include<iostream>
#include<string>
using namespace std;
class Publication
{
public:
	Publication() {};
	virtual void inputData(string name, int price, string date) { Name = name, Price = price, Date= date; }
	virtual void display() { cout << Name << " " << Price << " " << Date<< endl; }
	~Publication() {};
protected:
	string Name,Date;
	int Price;
};
class Book:public Publication
{
public:
	Book(int page) { Page = page; }
	void inputData(string name, int price, string date)
	{ Name = name, Price = price, Date=date; }
	void display() 
	{ cout << Name << " " << Price << " " <<Date <<" "<<Page<< endl; }
	~Book() {};
private:
	int Page;
};
class Tape :public Publication
{
public:
	Tape(string playtime) { Playtime = playtime; }
	void inputData(string name, int price, string date)
	{
		Name = name, Price = price, Date=date;
	}
	void display()
	{
		cout << Name << " " << Price << " " << Date << " " << Playtime<<endl;
	}
	~Tape() {};
private:
	string Playtime;
};
int main()
{
	Publication* P = NULL;
	Publication publication;
	Book book(300);
	Tape tape("00:48:10");
	P = &publication;
	P->inputData("Publication", 120, "1999-2-1");
	P->display();
	P = &book;
	P->inputData("Book", 30, "2009-1-1");
	P->display();
	P = &tape;
	P->inputData("Tape", 15, "2003-5-1");
	P->display();
	P = NULL;
	return 0;
}
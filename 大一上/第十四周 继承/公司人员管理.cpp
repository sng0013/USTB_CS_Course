#include<iostream>
#include<string>
using namespace std;
//人员类：基类（抽象类）
class Person
{
public:
	Person(string name);//构造函数：人名
	string GetName() { return name; }//返回人名
	int GetNun() { return number; }//返回编号
	virtual ~Person() {};//纯虚函数
	virtual float MonthSalary() = 0;//月薪
	virtual void SetSales(float sales) {};//设置销售额
	virtual void SetSumSales(float sales) {};//设置总销售额
protected:
	string name;
	static int count;
	int number;
	int level;
	float salary;
};
int Person::count = 0;
Person::Person(string n)
{
	name = n;
	count++;
}

class Manager :public Person
{public:
	Manager(string name) :Person(name) {};
	float MonthSalary() { return 8000; }
	~Manager() {};
};

class Partime_Technician :public Person
{public:
	Partime_Technician(string name) :Person(name) {};
	float MonthSalary() { return 16000; }
	~Partime_Technician() {};
};

class Sales_Manager :public Person
{public:
	Sales_Manager(string name) :Person(name) {};
	void SetSales(float sales) { Sales = sales; }
	float MonthSalary() {   return 5000 + (Sales * 0.005);}
	~Sales_Manager() {};
private:
	float Sales;
};

class Partime_Sales :public Person
{
public:
	Partime_Sales(string name) :Person(name) {};
	void SetSales(float sales) { Sales = sales; }
	float MonthSalary() { return 0.4*Sales; }
	~Partime_Sales() {};
private:
	float Sales;
};
int main() 
{
	int numOfPersons;
	cout << "Input the number of persons: " << endl;
	cin >> numOfPersons;
	Person** personArray = new Person * [numOfPersons];
	int i = 0;
	while (i < numOfPersons) {
		cout << "Input the person's name: " << endl;
		string aname;
		cin >> aname;
		cout << "Input the person's type: " << endl;
		int opt;
		switch (opt)
		{
		case 1: 
		{
			Manager manager(aname); 
			personArray[i] = &manager;
			cout << "A  Manager  is  added." << endl;
			break;
		}
		case 2: 
		{
			Partime_Technician technician(aname);
			personArray[i] = &technician;
			cout << "A  Partime_Technician  is  added." << endl;
			break;
		}
		case 3: 
		{
			Sales_Manager Smanager(aname);
			personArray[i] = &Smanager;
			cout << "Input sum of sales:" << endl;
			double sales;
			cin >> sales;
			Smanager.SetSales(sales);
			cout << "A  Sales_Manager  is  added." << endl;
			break;
		}
		case 4: 
		{
			Partime_Sales Psales(aname);
			personArray[i] = &Psales;
			cout << "Input his/her sales:" << endl;
			double sales;
			cin >> sales;
			Psales.SetSales(sales);
			cout << "A  Partime_Sales  is  added." << endl;
			break;
		}
		}
	}
	cout << "The  persons  are:  " << endl;
	for (i = 0; i < numOfPersons; ++i) {
		cout<<personArray[i]->GetNun()<<" "
			<< personArray[i]->GetName()<<" "
			<< personArray[i]->MonthSalary()<<endl;
	}
	for (i = 0; i < numOfPersons; ++i) {
		delete[]personArray[i];
	}
	return  0;
}
#include<iostream>
#include<string>
using namespace std;
class Animal
{public:
	virtual void what() = 0;
	string animal_name;
};
class Cat :public Animal
{public:
	void what() { animal_name = "Cat"; }
};
class Leopard :public Animal
{public:
	void what() { animal_name = "Leopard"; }
};
int main()
{
	Cat cat;
	cat.what();
	Leopard leopard;
	leopard.what();
	cout<<cat.animal_name<<endl<<leopard.animal_name;
}
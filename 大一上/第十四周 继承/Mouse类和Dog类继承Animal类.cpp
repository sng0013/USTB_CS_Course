#include<iostream>
using namespace std;
class Animal
{
public:
	virtual void sound() {
		cout << "..." << endl;
	}
};
class Mouse:public Animal
{
public:
	void sound() { cout << "zhi...zhi..." << endl; }
};
class Dog :public Animal
{
public:
	void sound() { cout << "wang...wang..." << endl; }
};
void f(Animal& p)
{
	p.sound();
}
int main()
{
	Animal animal;
	f(animal);
	Mouse mouse;
	f(mouse);
	Dog dog;
	f(dog);
}
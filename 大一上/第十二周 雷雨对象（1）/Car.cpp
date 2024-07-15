#include<iostream>
#include<cstring>
using namespace std;
class Car 
{
public:
	Car();
	Car(int, const char*, float, int);
	Car(Car&);
	~Car();
	void printCar();
	void setId(int);
private:
	int id;
	char* brand;
	float power;
	int numOfPersons;
};
Car::Car()
{
	cout << "Constructed without any parameter." << endl;
}
Car::Car(int pld,const char* pBrand,float pPower,int pNumOfPersons)
{
	id = pld;
	*brand = *pBrand;
	power = pPower;
	numOfPersons = pNumOfPersons;
	cout << "Constucted with all parameters." << endl;
}
Car::Car(Car& car)
{
	brand = new char[strlen(car.brand) + 1];
	if (brand != 0) strcpy_s(brand, strlen(car.brand) + 1, car.brand);
	id = car.id;
	power = car.power;
	numOfPersons = car.numOfPersons;
	cout << "Deep Constructed." << endl;
}
Car::~Car()
{
	delete[] brand;
	cout << "Deconstructed." << endl;
}
void Car::printCar()
{
	cout << "id:" << id << ", "
		<< "brand: " << brand << ", "
		<< "numOfPersons: " << numOfPersons << endl;
}
void Car::setId(int pld)
{
	id = pld;
}
int main()
{
	Car car1(1001, "Toyota", 1.8f, 5);
	Car car2(car1);
	car2.setId(1002);
	Car car3 = car1;
	car3.setId(1003);
	car1.printCar();
	car2.printCar();
	car3.printCar();
	return 0;
}
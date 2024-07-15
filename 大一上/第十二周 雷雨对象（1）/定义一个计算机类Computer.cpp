#include<iostream>
#include<cstring>
using namespace std;
class Computer
{public:
	Computer();
	Computer(int, char*, float, float);
	Computer(const Computer&);
	~Computer();
	void setId(int Id);
	void setHardDisk(float HDisk);
	void setMainFrequency(float Mfrequency);
	void printComputer();
private:
	int id;
	char *brand;
	float mainFrequency;
	float hardDisk;
};
Computer::Computer()
{
	cout << "Constructed without any parameter." << endl;
}
Computer::Computer(int pId, char* pBrand, float pMainFrequency, float pHardDisk)
{
	id = pId;
	mainFrequency = pMainFrequency;
	hardDisk = pHardDisk;
	brand = new char[strlen(pBrand) + 1];
	if (brand != 0) strcpy_s(brand, strlen(pBrand)+1,pBrand);
	cout << "Constructed with all parameters." << endl;
}
Computer::Computer(const Computer& Cp)
{
	//Computer复制构造函数
	id = Cp.id;
	mainFrequency = Cp.mainFrequency;
	hardDisk = Cp.hardDisk;
	brand = new char[strlen(Cp.brand) + 1];
	strcpy_s(brand, strlen(Cp.brand)+1,Cp.brand);
	cout << "Copy Constructed." << endl;
}
Computer::~Computer()
{
	cout << "Deconstructed." << endl;
}
void Computer:: setId(int Id) { id = Id; }
void Computer::setHardDisk(float HDisk) { hardDisk = HDisk; }
void Computer::setMainFrequency(float Mfrequency) { mainFrequency = Mfrequency; }
void Computer::printComputer()
{
	cout << "id: " << id << ", "
		<< "brand: " << brand << ", "
		<< "mainFrequency: " << mainFrequency << ", "
		<< "hardDisk: " << hardDisk << endl;
}
int main()
{
	Computer computer1(1001, "IBM", 1.8f, 500.f);
	Computer computer2(computer1);
	computer2.setId(1002);
	computer2.setMainFrequency(2.f);
	computer2.setHardDisk(100.f);
	Computer computer3(computer1);
	computer3.setId(1003);
	computer3.setMainFrequency(2.5f);
	computer3.setHardDisk(1500.f);
	Computer computer4 = computer1;
	computer4.setId(1004);
	computer4.setMainFrequency(2.f);
	computer4.setHardDisk(1200.f);
	computer1.printComputer();
	computer2.printComputer();
	computer3.printComputer();
	computer4.printComputer();
	return 0;
}


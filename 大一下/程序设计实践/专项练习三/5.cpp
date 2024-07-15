#include<iostream>
using namespace std;

class PoweredDevice
{
public:
	static int num;//用于计数有几台用电设备
	PoweredDevice() { 
		num++;
		cout << "A new PoweredDevice is constructed." << endl
			<< "There are " << num << " PoweredDevices in total." << endl;
	}
	virtual void display() {};
	~PoweredDevice() {};
};
int PoweredDevice::num = 0;

class Scanner:virtual public PoweredDevice
{
public:
	static int y;
	Scanner() {
		y++;
		cout << "A new Scanner is constructed." << endl
			<< "There are " << y << " Scanner in total." << endl;
	}
	~Scanner() {};
	void display(){ cout << "Scanner"; };
};
int Scanner::y = 0;

class Printer :virtual public PoweredDevice
{
public:
	static int z;
	Printer() {
		z++;
		cout << "A new Printer is constructed." << endl
			<< "There are " << z << " Printer in total." << endl;
	}
	~Printer() {};
	void display(){ cout << "Printer"; };
};
int Printer::z = 0;

class Copier:public Scanner,public Printer
{
public:
	static int u;
	Copier() {
		u++;
		cout << "A new Copier is constructed." << endl
			<< "There are " << u << " Copiers in total." << endl;
	}
	~Copier() {};
	void display(){ cout << "Copier"; };
};
int Copier::u = 0;

int main()
{
	PoweredDevice* arr[10];
	char ch;
	int i = 0;
	string a[10];
	while (cin >> ch)
	{

		if (ch == 's') { arr[i] = new Scanner; a[i] = "Scanner"; i++; continue; }
		if (ch == 'c') { arr[i] = new Copier; a[i] = "Copier"; i++; continue; }
		if (ch == 'p') { arr[i] = new Printer; a[i] = "Printer"; i++; continue; }
		if (ch == 'e') { break; }
	}
	cout << "The devices are:" << endl;
	for (int t = 0; t < i; t++)
	{
		cout << a[t] << endl;
	}
	return 0;
}

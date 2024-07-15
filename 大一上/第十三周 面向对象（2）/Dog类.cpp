#include<iostream>
using namespace std;
class Dog
{
public:
	void GetAge(int Age) { age=Age; }
	void SetAge(int Age) { age = Age; }
	void GetWeight(int Weight) { weight = Weight; }
	void SetWeight(int Weight) { weight = Weight; }
	int age, weight;
};
int main()
{
	Dog jack;
	jack.GetAge(2);
	jack.GetWeight(10);
	cout << jack.age << " " << jack.weight << endl;
	jack.SetAge(30);
	jack.SetWeight(10);
	cout << jack.age << " " << jack.weight << endl;
	return 0;
}

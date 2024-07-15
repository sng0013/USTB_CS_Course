#include<iostream>
using namespace std;
class Bed
{
public:
	virtual void usage() { cout << "Sleeping" << endl; }
};
class Sofa
{
public:
	virtual void usage() { cout << "Watching" << endl; }
};
class SleeperSofa :public Bed, public Sofa
{
	void usage() { cout << "Fold out" << endl; }
};
int main()
{
	Bed bed;
	Bed* B;
	Sofa sofa;
	SleeperSofa s;
	sofa.usage();
	B = &s;
	B->usage();
	B = &bed;
	B->usage();
	B = NULL;
	return 0;
}
#include<iostream>
using namespace std;
class Poem
{public:
	Poem() { 
		cout << "The most distant way in the world" << endl;
	    cout<<"is not the way from birth to the end" << endl; 
	}
	~Poem() { cout << "that you don't understand I love you."; }
};

int main()
{
	//定义一个对象
	Poem p;
	cout << "It is when I sit near you" << endl;
	return 0;
}
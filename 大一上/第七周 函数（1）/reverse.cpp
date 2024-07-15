#include<iostream>
using namespace std;
int reverse(int num)
{int t=0;
int s=0;
while(num)
{t=num%10;
num=num/10;
if(t==0&&s==0);
else s=s*10+t;
}return s;
}
int main()
{int woshidashuaibi,num;
cin>>num;
woshidashuaibi=reverse(num)	;
cout<<woshidashuaibi;
return 0;
}

#include <iostream>
using namespace std;

int main() {
   int i,max=0,min=0,v=0;//vΪ�����������
   scanf("%d",&v);
   max=min=v;

   for (i=2;i<=6;i++)
       {
       scanf("%d",&v);
       if (v>max)
       max=v;
       if (v<min)
       min=v;
       }
       cout<<max<<endl;

       return 0;
}


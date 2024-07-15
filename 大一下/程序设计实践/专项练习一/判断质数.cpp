#include <iostream>  
#include <cmath>  
using namespace std;

bool isPrime(int n)
{
    if (n <= 1) { return false; }//0��1��������
    if (n <= 3) { return true; }
    if (n % 2 == 0) { return false; }//�ų�ż��
    for (int i = 3; i * i <= n; i += 2)//�ڸ���n�ķ�Χ���ų�����
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    if (isPrime(n)) { cout << "Y"; }
    else { cout << "N"; }

    return 0;
}
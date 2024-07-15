#include <iostream>  
#include <cmath>  
using namespace std;

bool isPrime(int n)
{
    if (n <= 1) { return false; }//0和1不是素数
    if (n <= 3) { return true; }
    if (n % 2 == 0) { return false; }//排除偶数
    for (int i = 3; i * i <= n; i += 2)//在根号n的范围下排除奇数
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
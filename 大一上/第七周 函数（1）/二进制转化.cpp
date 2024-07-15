#include<iostream>
using namespace std;
int weishu(int n)
{
    int t = n, result = 0;
    while (t > 0)
    {
        t = t / 2;
        result++;
    }
    return result;
}
int main()
{
    int a[100];
    int n, i, ans;
    cin >> n;
    ans = weishu(n);
    for (i = 1; i <= ans; i++)
    {
        a[i] = n % 2;
        n = n / 2;
    }
    for (i = ans; i >= 1; i--)
    {
        cout << a[i];
    }
    cout << endl;
    return 0;
}
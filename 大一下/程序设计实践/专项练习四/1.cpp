#include <iostream>
#include<cstring>
using namespace std;
const int maxn = 5000;
const int maxn2 = maxn * 2;

//´óÊý´®µ¹Ðò
int read_str(char* s, int* a)
{
    int n = strlen(s);
    for (int i = 0; i < n; ++i)
    {
        a[i] = s[n - i - 1] - '0';
    }
    return n;
}

int main(int argc, char* argv[])
{
    char s[maxn];
    int a[maxn2], b[maxn2], c[maxn2];
    int n1, n2;
    cin >> s;
    n1 = read_str(s, a);
    cin >> s;
    n2 = read_str(s, b);

    for (int i = 0; i < n1 + n2; ++i) c[i] = 0;
    for (int i = 0; i < n1; i++)
        for (int j = 0; j < n2; j++)
        {
            c[i + j ] += a[i] * b[j];
        }

    for (int i = 0, m = 0; i < n1 + n2; ++i)
    {
        c[i] += m;
        m = c[i] / 10;
        c[i] %= 10;
    }

    int n = n1 + n2 - 1;
    for (; c[n] == 0; --n);
    for (; n >= 0; --n)
    {
        cout << c[n];
    }
    cout << endl;
    return 0;
}

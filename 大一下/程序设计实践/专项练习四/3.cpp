#include <iostream>
#include <vector>

const int maxn = 5000;
int a[maxn];

void swap(int* a,int i, int t)
{
    a[i] ^= a[t];
    a[t] ^= a[i];
    a[i] ^= a[t];
}

int main(int argc, char* argv[])
{
    int n;
    std::cin >> n;
    if (n <= 0 || n > maxn)
    {
        std::cout << "Invalid input array length:\n"
            "   must be in the range of 1 to "
            << maxn << std::endl;
    }

    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    for (bool flag = true; flag; )
    {
        flag = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                swap(a,i,i+1);
                flag = true;
            }
        }
        for (int i = n - 1; i > 0; i--)
        {
            if (a[i - 1] > a[i])
            {
                swap(a,i-1,i);
                flag = true;
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        std::cout << a[i] << (i < n - 1 ? ' ' : '\n');
    }
    return 0;
}

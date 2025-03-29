#include <iostream>
using namespace std;
bool vir[100000];
int main(void)
{
    int n = 100000;
    for (int i = 2; i <= n / i; i++)
    {
        if (!vir[i])
            for (int j = i * i; j <= n; j += i)
                vir[j] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vir[i])
            printf("%5d ", i);
    }
    return 0;
}
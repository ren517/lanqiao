#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    return b > 0 ? (gcd(b, a % b)) : a;
}
int main(void)
{
    int ans = 0;
    for (int i = 1; i <= 2020; i++)
    {
        for (int j = 1; j <= 2020; j++)
            if (i != j && gcd(i, j) == 1)
                ans++;
    }
    cout << ans + 1 << endl;
    return 0;
}
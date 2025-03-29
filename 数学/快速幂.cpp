#include <iostream>
using namespace std;
int quickpow(int a, int n)
{
    int ans = 1;
    while (n)
    {
        if (n & 1)
            ans = ans * a % 6;
        a = a * a % 6;
        n >>= 1;
    }
    return ans;
}

int main(void)
{
    cout << quickpow(3, 8) << endl;
    return 0;
}
#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e9 + 7;
ll quick_Pow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b % 2 == 1)
            ans = ans * a % N;
        a = a * a % N;
        b >>= 1;
    }
    return ans;
}

int main(void)
{
    ll ans;
    ans = quick_Pow(9, 10000) - quick_Pow(8, 10000) * 2 + quick_Pow(7, 10000);
    cout << ans % N << endl;

    return 0;
}
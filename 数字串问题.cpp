#include <iostream>
using namespace std;
typedef long long ll;
const ll N = 1e9 + 7;
ll quickpow(ll a, ll b)
{
    ll ans = 1;
    while (b)
    {
        if (b % 2 == 1)
            ans = a * ans % N;
        a = a * a % N;
        b >>= 1;
    }
    return ans;
}
int main(void)
{
    ll ans = quickpow(9, 10000) - quickpow(8, 10000) * 2 + quickpow(7, 10000);
    cout << ans % N << endl;
    return 0;
}
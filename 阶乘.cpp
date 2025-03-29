#include <iostream>
using namespace std;
typedef long long ll;
int main(void)
{
    int n;
    cin >> n;
    ll ans = 1;
    ll N = 1e9;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * i;
    }
    cout << ans << endl;
    return 0;
}
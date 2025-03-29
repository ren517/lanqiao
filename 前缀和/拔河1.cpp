#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1e5;
vector<ll> a;
ll arr[N];
ll sum[N];
int main(void)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
    }
    ll ans = LLONG_MAX;
    for (int l = 1; l <= n; l++)
    {
        for (int r = l; r <= n; r++)
        {
            ll temp = sum[r] - sum[l - 1];
            a.push_back(temp);
        }
    }
    sort(a.begin(), a.end());
    for (ll i = 1; i < a.size(); i++)
    {
        ans = min(ans, a[i] - a[i - 1]);
    }

    cout << ans << endl;

    return 0;
}
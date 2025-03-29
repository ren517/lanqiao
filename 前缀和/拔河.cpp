#include <iostream>
#include <vector>
// #include <algorithm>
typedef long long ll;
using namespace std;
const int N = 1e5;
vector<ll> a;
int n;
ll arr[N];
ll pre[N];

int main(void)
{
    cin >> n;
    ll ans = LLONG_MAX;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pre[i] = pre[i - 1] + arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        ll sum = 0;
        for (int j = i; j <= n; j++)
        {
            sum = pre[j] - pre[i - 1];
            a.push_back(sum);
        }
    }
    sort(a.begin(), a.end());

    for (ll i = 1; i < a.size(); i++)
    {
        ans = min(a[i] - a[i - 1], ans);
    }
    cout << ans << endl;
    return 0;
}
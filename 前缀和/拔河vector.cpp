#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

const int N = 1e5;
long long arr[N];
ll pre[N];
int n;
vector<ll> s;

int main()
{
    // 请在此输入您的代码
    ll ans = LLONG_MAX;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pre[i] = pre[i - 1] + arr[i];
    }

    for (int i = 1; i <= n; i++)
    {
        long long sum = 0;
        for (int j = i; j <= n; j++)
        {
            sum = pre[j] - pre[i - 1];
            s.push_back(sum);
        }
    }
    sort(s.begin(), s.end());
    for (ll i = 1; i < s.size(); i++)
    {
        ans = min(s[i] - s[i - 1], ans);
    }
    cout << ans << endl;
    return 0;
}
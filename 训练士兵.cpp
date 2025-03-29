#include <iostream>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
int n;
ll p[N]; // 一次的钱数
ll c[N]; // 次数
ll sum;
ll S;
ll ans = 0;
int main(void)
{
    cin >> n >> S;

    for (int i = 1; i <= n; i++)
    {
        cin >> p[i] >> c[i];
        sum += p[i];
    }

    while (sum >= S)
    {
        for (int i = 1; i <= n; i++)
        {
            if (c[i] == 0)
                continue;
            c[i]--;

            if (c[i] == 0)
            {
                sum -= p[i];
            }
        }
        ans += S;
    }

    for (int i = 1; i <= n; i++)
    {
        while (c[i] != 0)
        {
            c[i]--;
            ans += p[i];
        }
    }
    cout << ans << endl;
    return 0;
}
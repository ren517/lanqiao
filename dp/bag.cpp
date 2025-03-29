#include <iostream>
using namespace std;
typedef long long ll;

const int N = 105, M = 1010;

ll dp[N][M];
int main(void)
{
    int n, V;
    cin >> V >> n;
    for (int i = 1; i <= n; i++)
    {
        ll w, v;
        cin >> v >> w;
        for (int j = 1; j <= V; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= v)
                dp[i][j] = max(dp[i][j], dp[i - 1][j - v] + w);
        }
    }
    cout << dp[n][V];
    return 0;
}
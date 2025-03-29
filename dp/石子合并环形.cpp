#include <iostream>
using namespace std;
const int N = 1e3;
int arr[N];
int dp[N][N];
int sum[N];
int main(void)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        arr[i + n] = arr[i];
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        sum[i] = arr[i] + sum[i - 1];
    }

    for (int len = 2; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= n * 2; l++)
        {
            int r = len + l - 1;
            dp[l][r] = 1e5;
            for (int k = l; k < r; k++)
            {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + sum[r] - sum[l - 1]);
            }
        }
    }
    int ans = 1000;
    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, dp[i][n + i - 1]);
    }
    cout << ans << endl;

    return 0;
}
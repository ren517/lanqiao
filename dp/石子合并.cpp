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
        sum[i] = sum[i - 1] + arr[i];
        dp[i][i] = 0;
    }
    for (int len = 2; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            dp[l][r] = 1e5;
            for (int k = l; k < r; k++)
            {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + sum[r] - sum[l - 1]);
            }
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}

// 区间dp
// 5
// 1 3 4 2 5
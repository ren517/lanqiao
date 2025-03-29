#include <iostream>
using namespace std;
int main(void)
{
    const int n = 110;
    int arr[n];
    int dp[n][n];
    int sum[n];
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        sum[i] += sum[i - 1] + arr[i];
    }

    for (int len = 2; len <= N; len++)
    {
        for (int l = 1; l + len - 1 <= N; l++)
        {
            int r = l + len - 1;
            dp[l][r] = 1e5;
            for (int k = 1; k <= r; k++)
            {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r] + sum[r] - sum[l - 1]);
            }
        }
    }
    cout << dp[1][N] << endl;
    return 0;
}
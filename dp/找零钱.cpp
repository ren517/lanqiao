#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5;

int n;
int arr[N];
int dp[N];
int main(void)
{
    int m;
    cin >> m >> n;
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= m; i++)
    {
        dp[i] = 100;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[j] <= i)
            {
                dp[i] = min(dp[i - arr[j]] + 1, dp[i]);
            }
        }
        cout << dp[i] << ' ';
    }

    return 0;
}
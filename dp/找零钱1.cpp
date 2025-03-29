#include <iostream>
using namespace std;
int dp[100];
int arr[100];
int main(void)
{
    int n;
    int k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= k; i++)
    {
        dp[i] = 1e5;
    }

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[j] <= i)
                dp[i] = min(dp[i - arr[j]] + 1, dp[i]);
        }
        cout << dp[i] << ' ';
    }
    cout << endl;

    return 0;
}
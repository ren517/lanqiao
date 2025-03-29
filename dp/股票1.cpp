#include <iostream>
using namespace std;
const int N = 1e3;
int dp[N][2];
int arr[N];

int main(void)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    dp[1][0] = 0;
    dp[1][1] = -arr[1];
    for (int i = 2; i <= n; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + arr[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - arr[i]);
    }
    cout << dp[n][0] << endl;
    return 0;
}
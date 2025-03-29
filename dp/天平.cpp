#include <iostream>
#include <map>
using namespace std;
int arr[100];
long long dp[105][100010];
int n;

int main()
{
    // 请在此输入您的代码
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = sum; j >= 0; j--)
        {
            dp[i][j] = dp[i - 1][j] || dp[i - 1][abs(j - arr[i])] || dp[i - 1][j + arr[i]];
        }
    }
    int ans = 0;
    for (int i = 1; i <= sum; i++)
    {
        if(dp[n][i])
            ans++;
    }
    cout << ans << endl;
    return 0;
}
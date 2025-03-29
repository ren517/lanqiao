#include <iostream>
using namespace std;
const int M = 1000;
const int m = 1e5;
int arr[M];
int dp[m];

int main()
{
    // 请在此输入您的代码
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        dp[arr[i]] = 1;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[j] <= i && dp[i] == 0)
                dp[i] = dp[i - arr[j]];
        }
    }
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        if (!dp[i])
            ans++;
    }
    if (ans > 2000)
        cout << "INF" << endl;
    else
        cout << ans << endl;
    return 0;
}
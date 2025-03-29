#include <iostream>
using namespace std;
const int N = 105;
int arr[N];
int dp[N][N]; // 选n个砝码能称的重量
int main(void)
{
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = sum; j >= 0; j--)
        {
            dp[i][j] = dp[i - 1][j] || dp[i - 1][j + arr[i]] || dp[i - 1][abs(arr[i] - j)];
        }
    int ans = 0;
    for (int i = 1; i <= sum; i++)
    {
        if (dp[n][i] == 1)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
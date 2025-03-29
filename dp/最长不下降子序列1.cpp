#include <iostream>
using namespace std;
const int N = 100;
int arr[N] = {0, 2, 5, 3, 4, 1, 7, 6};
int dp[N];
int main(void)
{
    int n = 7;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for (int j = 1; j <= i; j++)
        {
            if(arr[i]>arr[j])
                dp[i] = max(dp[j] + 1, dp[i]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dp[i]);
    cout << ans << endl;
    return 0;
}
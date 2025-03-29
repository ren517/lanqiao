#include <iostream>
using namespace std;

int dp[100][100];
int main(void)
{
    int v[10], w[10];
    int n, c;
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= c; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= v[i])
                dp[i][j] = max(dp[i - 1][j], dp[i][j - v[i]] + w[i]);
        }
    }
    cout << dp[n][c] << endl;
    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(void)
{
    string a = "ABCBDAB";
    string b = "BDCABA";
    int dp[100][100];
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (a[i] == b[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
        }
    }
    cout << dp[7][6];

    return 0;
}
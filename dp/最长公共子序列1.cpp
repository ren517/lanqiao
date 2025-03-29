#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    string a = "ABCBDAB";
    string b = "BDCABA";

    int dp[100][100];
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            if (a[i] == b[j])
                dp[i + 1][j + 1] = dp[i][j] + 1; // 不能用-1，防止溢出
            else
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    cout << dp[a.size()][b.size()] << endl;
    return 0;
}
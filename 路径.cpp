#include <iostream>
using namespace std;
typedef long long ll;
ll dp[2023];
int gcd(int a, int b)
{
    return b > 0 ? (gcd(b, (a % b))) : a;
}
int main(void)
{
    dp[1] = 0;
    for (int i = 2; i <= 2021; i++)
        dp[i] = 1e10;
    for (int i = 1; i <= 2021; i++)
    {
        for (int j = i + 1; j <= i + 21; j++)
        {
            dp[j] = min(dp[i] + i * j / gcd(i, j), dp[j]);
        }
    }
    cout << dp[2021] << endl;
}
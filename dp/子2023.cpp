#include <iostream>
using namespace std;
string s;
long long dp[5];
int main(void)
{
    for (int i = 1; i <= 2023; i++)
    {
        s += to_string(i);
    }

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '2')
            dp[1]++;
        if (s[i] == '0')
            dp[2] += dp[1];
        if (s[i] == '2')
            dp[3] += dp[2];
        if (s[i] == '3')
            dp[4] += dp[3];
    }
    cout << dp[4] << endl;

    return 0;
}

#include <iostream>
using namespace std;
const int N = 1e5;
int arr[N] = {0, 2, 5, 3, 4, 1, 7, 6};
int dp[N];

int main(void)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (arr[j] < arr[i])
            {
                dp[i] = max(dp[j] + 1, dp[i]);
            }
        }
        cout << dp[i] << endl;
    }

    return 0;
}
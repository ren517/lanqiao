#include <iostream>
#include <algorithm>
using namespace std;

int arr[100][100] = {0};
int sum[100][100] = {0};
int mian(void)
{
    int m, n;
    cin >> m >> n;


    for (int i = 1; i <= m; i++)
        for (int j = 1; i <= n; j++)
        {
            cin >> arr[i][j];
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
        }
    if (sum[m][n] == 0)
    {
        cout << 0 << endl;
    }
    int ans = 1;
    for (int a = 1; a <= m; a++)
    {
        for (int b = 1; b <= n; b++)
        {
            for (int c = a + ans, d = b + ans, k = ans + 1; c <= m && b <= n; c++, b++, k++) // 剪枝
            {
                int temp1 = sum[c][d] - sum[a - 1][d] - sum[c][b - 1] + sum[a - 1][b - 1];
                int temp2 = sum[c - 1][d - 1] - sum[a][d - 1] - sum[c - 1][b] + sum[a][b];
                if (temp1 - temp2 == (k - 1) << 2)
                {
                    ans = k;
                }
            }
        }
    }
    cout << ans * ans << endl;
    return 0;
}
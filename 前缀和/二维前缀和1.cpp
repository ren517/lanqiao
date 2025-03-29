#include <iostream>
using namespace std;
const int N = 1000;
int arr[N][N];
int sum[N][N];
int main(void)
{
    int n = 4;
    int a = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++, a++)
        {
            arr[i][j] = a;
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
            cout << sum[i][j] << ' ';
        }
        cout << endl;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int ans = sum[i][j] - sum[2][j] - sum[i][2] + sum[2][2];
            if (ans > 0)
                cout << ans << ' ';
            else
                cout << 0 << ' ';
        }
        cout << endl;
    }

    return 0;
}
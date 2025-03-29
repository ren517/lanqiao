#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 500;
int main()
{
    // 请在此输入您的代码
    int n, m, a;
    ll k;
    cin >> n >> m >> k;
    a = min(m, n);
    ll sum[N][N];
    ll temp;
    int arr[N][N];
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> arr[i][j];
            sum[i][j] += sum[i][j - 1] + arr[i][j - 1];
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 1; k <= a; k++)
            {
                for (int g = 1; g <= a; g++)
                    temp = sum[k][g] - sum[i - k][j - g];
                if (temp < k)
                    ans++;
            }
    cout << ans << endl;

    return 0;
}
#include <iostream>
using namespace std;
const int N = 1e3;
int pos[N][N];
bool a[N], b[N], c[N], d[N];
int n;
int ans;
void dfs(int dep)
{
    if (dep > n)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
                if (pos[i][j] == 1)
                    cout << '(' << i << ',' << j << ')' << ' ';
        }
        cout << endl;
        ans++;
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        if (a[i] || b[dep] || c[i - dep + n] || d[i + dep])
            continue;
        pos[dep][i] = 1;
        a[i] = b[dep] = c[i - dep + n] = d[i + dep] = true;
        dfs(dep + 1);
        pos[dep][i] = 0;
        a[i] = b[dep] = c[i - dep + n] = d[i + dep] = false;
    }
}
int main(void)
{

    cin >> n;
    dfs(1);
    cout << ans << endl;
    return 0;
}
#include <iostream>
using namespace std;

const int N = 15;
int n, k;
int arr[N][N];
int ans[1000];
bool mark[N][N][N][N];
bool vir[N][N];
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int f = 0;

void dfs(int x, int y, int dep)
{
    if (f)
        return;
    if (x == n && y == n && dep == n * n - 1)
    {
        f = 1;
        for (int i = 0; i < dep; i++)
            cout << ans[i];
        cout << endl;
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];

        if (xx >= 1 && xx <= n && yy >= 1 && yy <= n && arr[xx][yy] == (dep + 1) % k)
        {
            if (vir[xx][yy])
                continue;
            vir[xx][yy] = true;
            mark[xx][yy][x][y] = true;
            mark[x][y][xx][yy] = true;
            ans[dep] = i;
            if (i == 1 || i == 3 || i == 5 || i == 7)
            {
                if (!mark[xx][y][x][yy])
                    dfs(xx, yy, dep + 1);
            }
            else
                dfs(xx, yy, dep + 1);
            vir[xx][yy] = false;
            mark[xx][yy][x][y] = false;
            mark[x][y][xx][yy] = false;
        }
    }
}
int main(void)
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];
    }
    vir[1][1] = true;
    dfs(1, 1, 0);
    if (!f)
        cout << -1 << endl;

    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

const int N = 1e3;
struct proint
{
    int x, y;
};
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
char a[N][N];
bool vir[N][N];
void dfs(int x, int y)
{
    if(a[x][y] != '#')
        return;
    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if(vir[xx][yy])
            continue;
        vir[xx][yy] = true;
        if (a[xx][yy] == '#')
        {
            vir[xx][yy] = true;
            dfs(xx, yy);
        }
    }
}

int main(void)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (!vir[i][j] && a[i][j] == '#')
            {
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
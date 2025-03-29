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
void bfs(int x, int y)
{
    queue<proint> q;
    vir[x][y] = true;
    proint temp = {x, y};
    q.push(temp);
    while (q.size())
    {
        temp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int xx = temp.x + dx[i];
            int yy = temp.y + dy[i];
            if (vir[xx][yy])
                continue;
            if (a[xx][yy] == '#')
            {
                proint a = {xx, yy};
                q.push(a);
                vir[xx][yy] = true;
            }
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
                bfs(i, j);
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
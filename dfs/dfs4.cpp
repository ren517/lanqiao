// error
#include <iostream>
using namespace std;

const int MAXN = 100;
int amin = 1e8;
int arr[MAXN][MAXN];
bool vir[MAXN][MAXN];
int endx, endy;
int fangan = 0;

// 方向数组：右、下、左、上
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void dfs(int x, int y, int dep)
{
    if (x == endx && y == endy)
    {
        if (dep < amin)
            amin = dep;
        fangan++;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 检查边界和是否可通行
        if (nx >= 1 && nx <= MAXN && ny >= 1 && ny <= MAXN &&
            arr[nx][ny] == 1 && !vir[nx][ny])
        {
            vir[nx][ny] = true;
            dfs(nx, ny, dep + 1);
            vir[nx][ny] = false; // 回溯
        }
    }
}

int main()
{
    int posx, posy;
    int startx, starty;
    cin >> posx >> posy;

    for (int i = 1; i <= posx; i++)
    {
        for (int j = 1; j <= posy; j++)
        {
            cin >> arr[i][j];
        }
    }

    cin >> startx >> starty >> endx >> endy;

    // 标记起点为已访问
    vir[startx][starty] = true;
    dfs(startx, starty, 1);

    cout << amin << ' ' << fangan << endl;

    return 0;
}
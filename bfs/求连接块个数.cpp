#include <iostream>
#include <queue>
using namespace std;

struct point
{
    int x, y;
};
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
const int N = 1e3;
int arr[N][N];
bool vir[N][N];
void bfs(int x, int y)
{
    point p = {x, y};
    queue<point> q;
    q.push(p);
    while (q.size())
    {
        point temp = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int xx = temp.x + dx[i];
            int yy = temp.y + dy[i];
            if (vir[xx][yy])
                continue;
            if (arr[xx][yy] == 1)
            {
                point a = {xx, yy};
                vir[xx][yy] = true;
                q.push(a);
            }
        }
    }
}
int main(void)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> arr[i][j];
    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if(arr[i][j] == 1 && !vir[i][j])
            {
                bfs(i, j);
                ans++;
            }
        }
    cout << ans << endl;
    return 0;
}
/*
5
1 0 0 0 0
1 0 1 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 0 0
*/
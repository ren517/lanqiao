#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct e
{
    int x, y;
};

const int N = 1005;
int n;
string arr[N];
bool vir[N][N];
int ans = 0;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int f = 0;

void bfs(int x, int y)
{
    queue<e> q;
    vir[x][y] = true;
    e e1 = {x, y};
    q.push(e1);

    while (q.size())
    {
        e temp = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int xx = temp.x + dx[i];
            int yy = temp.y + dy[i];
            if (xx >= n || xx < 0 || yy >= n || yy < 0)
                continue;
            if (!vir[xx][yy] && arr[xx][yy] == '#')
            {
                e a = {xx, yy};
                q.push(a);
                vir[xx][yy] = true;
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!vir[i][j] && arr[i][j] == '#')
            {
                bfs(i, j);
                sum++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            f = 0;
            if (arr[i][j] == '#')
            {
                if ((i == 0 && j == 0) || (i == n - 1 && j == 0) || (i == 0 && j == n - 1) || (i == n - 1 && j == n - 1))
                    f = 2;
                else if (i == 0 || i == n - 1 || j == n - 1 || j == 0)
                    f = 1;
                for (int k = 0; k < 4; k++)
                {
                    if (i + dx[k] > 1 && j + dy[k] < n)
                    {
                        if (arr[i + dx[k]][j + dy[k]] == '#')
                            f++;
                    }
                }
            }
            if (f == 4)
            {
                ans++;
            }
        }
    }

    cout << sum - ans << endl;
    return 0;
}
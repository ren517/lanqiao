#include <iostream>
using namespace std;
const int N = 25;
int arr[N][N];
bool vir[N][N];
int nor[N];
int we[N];
int xp[N];
int yp[N];
int tempn[N];
int tempw[N];
int n;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1,0};
void dfs(int x, int y)
{
    if (x == n - 1 && y == n - 1)
    {
        int temp = 1;
        for (int i = 0; i < n; i++)
        {
            if (nor[i] == tempn[i] && we[i] == tempw[i])
                temp++;
        }
        if (temp == n)
        {
            for (int i = 0; i < n; i++)
            {
                cout << xp[i] + yp[i] - 2 << ' ';
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (vir[x][y])
            return;
        vir[x][y] = true;
        tempn[y]++;
        xp[i] = x;
        tempw[x]++;
        yp[i] = y;
        if (x + dx[i] > 0 && x + dx[i] < n && y + dy[i] > 0 && y + dy[i] < n)
            dfs(x + dx[i], y + dy[i]);
    }
}
int main()
{
    // 请在此输入您的代码

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            arr[i][j] = i + j - 2;
        }
    }
    for (int i = 1; i <= n; i++)
        cin >> nor[i];
    for (int i = 1; i <= n; i++)
        cin >> we[i];

    return 0;
}
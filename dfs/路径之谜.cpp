#include <iostream>
#include <vector>
using namespace std;
const int N = 25;
int arr[N][N];
bool vir[N][N];
int nor[N];
int we[N];
int x[N];
int y[N];
int tempn[N];
int tempw[N];
int n;
vector<int> ans;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int f = 0;
bool dfs(int x, int y, int dep)
{
    if (f)
        return true;
    ans.push_back((x - 1) * n + y - 1); // 记录当前节点
    if (x == n && y == n)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (tempn[i] == nor[i] && tempw[i] == we[i])
            {
                sum++;
            }
        }
        if (sum == n)
        {
            f = true;
            return true;
        }
        ans.pop_back(); // 回溯
        return false;
    }

    for (int i = 0; i < 4; i++)
    {
        int xx = x + dx[i];
        int yy = y + dy[i];
        if (xx >= 1 && xx <= n && yy >= 1 && yy <= n )
        {
            if(vir[xx][yy])
                continue;
            if (tempn[yy] > nor[yy] || tempw[xx] > we[xx])
                continue;
            vir[xx][yy] = true;
            tempn[yy]++;
            tempw[xx]++;
            if (dfs(xx, yy, dep + 1))
            {
                return true;
            }
            vir[xx][yy] = false; // 回溯
            tempn[yy]--;
            tempw[xx]--;
        }
    }
    ans.pop_back(); // 回溯
    return false;
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
    vir[1][1] = true;
    tempw[1]++;
    tempn[1]++;

    if (dfs(1, 1, 0))
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
    cout << endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
vector<int> ans;
const int N = 11;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int n;
bool vir[N][N];
bool tag[N][N][N][N]; // 判断连线是否相交
int arr[N][N];
int route[N * N];
int k;
int f = 0;

void dfs(int strx, int stry, int dep)
{
    if (f)
        return;
    ans.push_back((strx - 1) * n + stry);
    if (strx == n && stry == n && dep == n * n - 1)
    {
        f = 1;
        return;
    }
    for (int i = 0; i < 8; i++)
    {
        if (strx + dx[i] >= 1 && strx + dx[i] <= n && stry + dy[i] >= 1 && stry + dy[i] <= n && arr[strx + dx[i]][stry + dy[i]] == (dep + 1) % k)
        {
            if (vir[strx + dx[i]][stry + dy[i]])
                continue;
            vir[strx + dx[i]][stry + dy[i]] = true;
            tag[strx][stry][strx + dx[i]][stry + dy[i]] = true;
            tag[strx + dx[i]][stry + dy[i]][strx][stry] = true;
            if (i == 1 || i == 3 || i == 5 || i == 7)
            {
                if (!tag[strx][stry + dy[i]][strx + dx[i]][stry])
                    dfs(strx + dx[i], stry + dy[i], dep + 1);
            }
            else
            {
                dfs(strx + dx[i], stry + dy[i], dep + 1);
            }

            vir[strx + dx[i]][stry + dy[i]] = false;
            tag[strx][stry][strx + dx[i]][stry + dy[i]] = false;
            tag[strx + dx[i]][stry + dy[i]][strx][stry] = false;
        }
    }
    if (!f)
        ans.pop_back();
}

int main()
{
    // 请在此输入您的代码
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> arr[i][j];
        }
    }
    vir[1][1] = true;
    dfs(1, 1, 0);
    if (f == 0)
        cout << -1;
    for (auto a : ans)
        cout << a << ' ';
    cout << endl;

    return 0;
}

// 徉例
// 3 3
// 0 2 0
// 1 1 1
// 2 0 2
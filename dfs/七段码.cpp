// dfs + 并查集
#include <iostream>
using namespace std;

const int N = 10;

int n = 7;
int ans = 0;
int p[N];
bool vir[N];
int e[N][N];

int find(int a)
{
    if (p[a] == a)
        return a;
    else
        return p[a] = find(p[a]);
}

void dfs(int dep)
{
    if (dep == n + 1)
    {
        for (int i = 1; i <= n; i++)
            p[i] = i;

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (e[i][j] && vir[i] && vir[j])
                    p[find(i)] = find(j);

        int cnt = 0;
        for (int i = 1; i <= n; i++)
            if (vir[i] && p[i] == i)
                cnt++;
        if (cnt == 1)
            ans++;
        return;
    }
    vir[dep] = 1;
    dfs(dep + 1);

    vir[dep] = 0;
    dfs(dep + 1);
}
int main(void)
{
    e[1][2] = e[1][6] = 1;
    e[2][1] = e[2][7] = e[2][3] = 1;
    e[3][2] = e[3][7] = e[3][4] = 1;
    e[4][3] = e[4][5] = 1;
    e[5][4] = e[5][7] = e[5][6] = 1;
    e[6][1] = e[6][7] = e[6][5] = 1;
    e[7][2] = e[7][3] = e[7][5] = e[7][6] = 1;

    dfs(1);
    cout << ans << endl;
    return 0;
}
#include <iostream>
using namespace std;
// 求1-n的全排列

int n = 3;
const int N = 1e5;
int a[N] ;
bool vis[N];
void dfs(int dep)
{
    if (dep == n + 1)
    {
        for (int i = 1; i <= n; i++)
            cout << a[i];
        cout << '\n';
        return;
    }
    // 11-17是出口
    for (int i = 1; i <= n; i++)
    {
        // 排除不合法的路径
        if (vis[i])
            continue;

        // 修改状态
        vis[i] = true;
        a[dep] = i;

        // 下一层
        dfs(dep + 1);

        // 恢复现场
        vis[i] = false;
        // a[dep] = 0 可以省略
    }
}
int main(void)
{
    dfs(1);
    return 0;
}
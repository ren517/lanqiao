#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5;
int e[N];
int n;
int big = 0;

void dfs(int x, int next, int dep)
{
    if (dep > n)
        return;
    if (x == next)
    {
        big = max(big, dep);
        return;
    }
    dfs(x, e[next], dep + 1);
}

int main()
{
    // 请在此输入您的代码
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> e[i];
    }
    for (int i = 1; i <= n; i++)
    {
        dfs(i, e[i], 1);
        cout << big << ' ';
    }
    cout << big << endl;
    return 0;
}
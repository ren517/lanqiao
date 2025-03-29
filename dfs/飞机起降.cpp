#include <iostream>
using namespace std;
int n, t;
const int N = 15;
int T[N], D[N], L[N];// T到达时间  D到达后可巡航时间  L降落需要时间
bool vir[N];

bool dfs(int dep, int time)
{
    if (dep == n)
    {
        return true;
    }

    for (int i = 1; i <= n; i++)
    {
        if (!vir[i])
        {
            vir[i] = true;
            if (T[i] + D[i] < time)
            {
                vir[i] = false;
                return false;
            }

            int t = max(time, T[i]) + L[i]; // 下一架飞机降落后的时间
            if (dfs(dep + 1, t))
                return true;

            vir[i] = false;
        }
    }
    return false;
}
int main()
{
    // 请在此输入您的代码
    cin >> t;
    while (t)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> T[i] >> D[i] >> L[i];
        }
        if (dfs(0, 0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        for (int i = 1; i <= n; i++)
        {
            vir[i] = false;// 每完成一次查找后初始化
        }
        t--;
    }
    return 0;
}
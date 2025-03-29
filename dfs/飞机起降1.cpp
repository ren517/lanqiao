#include <iostream>
using namespace std;
const int N = 15;
int T[N], D[N], L[N];
int k;
int n;
bool vir[N];

bool dfs(int dep, int time)
{
    if (dep == n)
        return true;
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
            int t = max(time, T[i]) + L[i];
            if (dfs(dep + 1, t))
                return true;

            vir[i] = false;
        }
    }
    return false;
}
int main(void)
{
    cin >> k;
    while (k)
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
            vir[i] = false;
        k--;
    }
    return 0;
}
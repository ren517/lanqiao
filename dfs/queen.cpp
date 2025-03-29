#include <iostream>
using namespace std;
int n, ans;
const int N = 1e5;
int pos[N], c[N], p[N], q[N];

void print()
{
    for (int i = 1; i <= n; i++)
        cout << pos[i];
    cout << endl;
}
void dfs(int i)
{
    if (i > n)
    {
        ans++;
        print();
        return;
    }
    for (int j = 1; j <= n; j++)
    {
        if (c[j] || p[i + j] || q[i - j + n])
            continue;
        pos[i] = j;
        c[j] = p[i + j] = q[i - j + n] = 1;
        dfs(i + 1);
        c[j] = p[i + j] = q[i - j + n] = 0;
    }
}

int main(void)
{
    cin >> n;
    dfs(1);
    cout << ans << endl;
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
const int N = 1000;
struct edge
{
    int v, w; // v 是终边，w权值
};
vector<edge> e[N];

void dfs(int u, int fa)
{
    for (auto &ed : e[u])
    {
        int v = ed.v;
        int w = ed.w;
        if (v == fa)
            continue;
        cout << u << "->" << v << ':' << w;
        dfs(v, u);
    }
}
int main(void)
{
    int n, m; // n表示点的个数，m为边的个数
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        e[a].push_back({b, c}); // a -> b weight = c
        e[b].push_back({a, c}); // b -> a weight = c
    }
    dfs(1, 0);
}
// 4 3
// 1 2 10
// 2 3 20
// 3 4 30
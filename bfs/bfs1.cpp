
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool vir[100];
struct edge
{
    int v, w;
};
vector<edge> e[100];
queue<int> q;
int main(void)
{
    int n;
    cin >> n;
    q.push(1);
    for (int i = 1; i <= n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        e[a].push_back({b, c});
        e[b].push_back({a, c});
    }
    vir[1] = true;
    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();
        for (auto ed : e[temp])
        {
            if (vir[(ed.v)])
                continue;
            vir[ed.v] = true;
            q.push(ed.v);
            cout << temp << "->" << ed.v << ':' << ed.w << endl;
        }
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1000;
struct edge
{
    int x;
};
bool vir[N];
vector<edge> e[N];
queue<edge> q;
void bfs()
{
    vir[1] = 1;
    q.push({1});
    while (q.size())
    {
        auto x = q.front();
        q.pop();
        for (edge y : e[x])
        {
            if (vir[y.x])
                continue;
        }
    }
}

int main(void)
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        int a, b;
        cin >> a >> b;
        e[a].push_back({a});
        e[b].push_back({b});
    }

    return 0;
}
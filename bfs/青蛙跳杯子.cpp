#include <iostream>
#include <queue>
#include <map>
using namespace std;
string a, b;
int d[6] = {-3, -2, -1, 1, 2, 3};
int n;
queue<string> q;
map<string, int> ans;
int bfs()
{
    q.push(a);
    ans[a] = 0;
    while (q.size())
    {
        string ss = q.front();
        q.pop();
        int temp = ans[ss];
        int x = ss.find('*');
        for (int i = 0; i < 6; i++)
        {
            int z = x + d[i];
            if (z >= 0 && z < n)
            {
                swap(ss[x], ss[z]);
                if (ans[ss] == 0)
                {
                    ans[ss] = temp + 1;
                    if (ss == b)
                        return ans[ss];
                    q.push(ss);
                }
                swap(ss[x], ss[z]);
            }
        }
    }
    return -1;
}
int main(void)
{
    cin >> a >> b;
    n = a.size();

    cout << bfs() << endl;
    return 0;
}
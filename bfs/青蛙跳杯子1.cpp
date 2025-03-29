#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;
int d[6] = {-3, -2, -1, 1, 2, 3};
queue<string> q;
string a, b;
int n;
map<string, int> mp;

int bfs()
{
    q.push(a);
    while (q.size())
    {
        string ss = q.front();
        q.pop();
        int temp = ss.find('*');
        int x = mp[ss];
        for (int i = 0; i < 6; i++)
        {
            int t = temp + d[i];
            if (t >= 0 && t < n)
            {
                swap(ss[t], ss[temp]);
                if (mp[ss] == 0)
                {
                    q.push(ss);
                    mp[ss] = x + 1;
                    if (ss == b)
                        return mp[ss];
                }
                swap(ss[t], ss[temp]);
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
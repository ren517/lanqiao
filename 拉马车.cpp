#include <iostream>
#include <string>
#include <queue>
using namespace std;
const int N = 1e7;
string a;
string b;
queue<char> a1;
queue<char> b1;
int main(void)
{
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++)
        a1.push(a[i]);
    for (int i = 0; i < b.size(); i++)
        b1.push(b[i]);
    string temp;
    for (int i = 1; i < N; i++)
    {
        if (a.size())
        {
            if (int m = temp.find(a.front()))
            {
                for (int i = temp.size(); i >= m; i--)
                {
                    a.push_back(temp[i]);
                }
                temp.resize(m);
            }
            else
            {
                temp += a.front();
                a.pop_back();
            }
        }
        if (b.size())
        {
            if (int m = temp.find(b.front()))
            {
                for (int i = temp.size(); i >= m; i--)
                {
                    b.push_back(temp[i]);
                }
                temp.resize(m);
            }
            else
            {
                temp += b.front();
                b.pop_back();
            }
        }
        if (a.empty() || b.empty())
            break;
    }
    if (a.size())
    {
        for (auto e : a)
            cout << e;
        cout << endl;
    }

    if (b.size())
    {
        for (auto e : b)
            cout << e;
        cout << endl;
    }
    if(a.size()&&b.size())
        cout << -1;
    return 0;
}
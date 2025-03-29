#include <iostream>
#include <map>
using namespace std;
map<char, int> mp;
int main(void)
{
    string n;
    cin >> n;
    int ans = 0;

    for (int i = 0; i < n.size(); i++)
    {
        mp.clear();
        int temp = 0;
        for (int j = i; j < n.size(); j++)
        {
            if (mp[n[j]] == 0)
            {
                temp++;
                mp[n[j]]++;
            }
            ans += temp;
        }
    }
    cout << ans << endl;
    return 0;
}
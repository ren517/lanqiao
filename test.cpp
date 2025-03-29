#include <iostream>
#include <map>
using namespace std;
map<char, int> mp;
const int N = 1e5 + 10;

int sum[N];
int main()
{
    // 请在此输入您的代码
    string a;
    cin >> a;

    sum[0] = 1;
    mp[a[0]]++;
    int ans = 1;
    for (int i = 1; i < a.size(); i++)
    {
        if (!mp[a[i]])
        {
            sum[i] = sum[i - 1] + 1;
        }
        if (mp[a[i]])
            sum[i] = sum[i - 1];
        mp[a[i]]++;

        ans += sum[i];
    }
    for (int l = 1; l < a.size(); l++)
    {
        mp[a[l]]--;
        if (mp[a[l]] == 0)
        {
            for (int i = l; i < a.size(); i++)
                sum[i]--;
        }
        sum[l] = 1;
        for (int j = l; j < a.size(); j++)
        {
            ans += sum[j];
        }

    }

    cout << ans << endl;
    return 0;
}
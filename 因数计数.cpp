#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int arr[N];
int num[N];
map<int, int> mp;
int main(void)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
        if (mp[arr[i]] > 1)
        {
            num[arr[i]]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= mp[1]; j++)
        {
            if (arr[i] != 1)
                num[arr[i]]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 2; j * j < arr[i]; j++)
        {
            if (arr[i] % j == 0)
            {
                if (arr[i] == j)
                    continue;
                if (mp[j])
                {
                    num[arr[i]]++;
                }
                if (mp[arr[i] / j])
                    num[arr[i]]++;
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ll temp1, temp2;
        temp1 = 0;
        temp2 = 1;
        if (num[arr[i]])
        {
            int temp3 = num[arr[i]];
            while (temp3)
            {
                temp1 = temp3;
                temp2 = temp2 * temp1;
                temp3--;
            }
            ans += temp2;
        }
    }
    cout << ans << endl;
    return 0;
}
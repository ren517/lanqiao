#include <iostream>
#include <map>

using namespace std;
const int N = 1e5;
int arr[N];
map<int, int> mp;

int main(void)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int l = 1;
    int ans = 0;
    for (int r = 1; r <= n; r++)
    {
        mp[arr[r]]++;
        while(mp[arr[r]] > 1)
        {
            mp[arr[l]]--;
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << endl;

    return 0;
}
#include <iostream>
#include <map>
using namespace std;
int main(void)
{
    int arr[100];
    map<int, int> mp;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    int ans = 0;
    for (int r = 1, l = 1; r <= n; r++)
    {
        mp[arr[r]]++;
        while (mp[arr[r]] > 1)
        {
            mp[arr[l]]--;
            l++;
        }
        ans = max(ans, r - l + 1);
    }
    cout << ans << endl;
    return 0;
}
// 双指针+哈希表
// 5
// 1 2 2 3 5
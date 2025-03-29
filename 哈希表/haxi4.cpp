#include <iostream>
#include <map>
using namespace std;
int main(void)
{
    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int goal = 5;
    int sum[9];
    sum[0] = arr[0];
    for (int i = 1; i <= 9; i++)
    {
        sum[i] = arr[i] + sum[i - 1];
    }
    map<int, int> has;
    has[goal] = 1;
    int ans = 0;
    for (int i = 0; i < 9; i++)
    {
        ans += has[sum[i]];
        if (has[sum[i]] != 0)
        {
            cout << i + 1 << endl;
            cout << arr[i] << ' ' << goal - arr[i] << endl;
        }
        has[sum[i] + goal]++;
    }
    cout << ans << endl;
    return 0;
}
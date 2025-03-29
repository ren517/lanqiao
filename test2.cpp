#include <iostream>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int n;
    int arr[1005];
    int l, r;
    l = 1;
    r = 2;
    int ans = 0;

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    while (r != n)
    {
        if (arr[r] < arr[r + 1])
        {
            ans = max(ans, r - l + 1);
            r++;
        }
        else
        {
            l = r;
            r++;
        }
    }
    cout << ans << endl;
    return 0;
}
#include <iostream>
using namespace std;
const int N = 1e5;
int arr[N];
int maxl[N];
int maxr[N];
int main(void)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    maxl[1] = arr[1];
    for (int i = 1; i <= n; i++)
    {
        maxl[i] = max(maxl[i - 1], arr[i]);
    }
    maxr[n] = arr[n];
    for (int i = n; i >= 1; i--)
    {
        maxr[i] = max(maxr[i + 1], arr[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += min(maxl[i], maxr[i]) - arr[i];
    }
    cout << ans << endl;
    return 0;
}
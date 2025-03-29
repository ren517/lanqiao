#include <iostream>
#include <map>
using namespace std;
int main(void)
{
    map<int, int> has;
    int ans = 0;
    int arr[] = {1, 2, 3, 1, 1, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++)
    {
        ans += has[arr[i]];
        has[arr[i]]++;
    }
    cout << ans << endl;

    return 0;
}
#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    map<int, int> has;
    int k = 3;
    int ans = 0;
    for (int i = 0; i < 10; i++)
    {
        int x = arr[i] + k;
        if (x >= 1 && x <= 100)
            ans += has[x];
        x = arr[i] - k;
        if (x >= 1 && x <= 100)
            ans += has[x];
        if (has[k] != 0)
        {
            cout << arr[i] << ' ' << arr[i] - k << endl;
        }
        has[arr[i]]++;
    }
    cout << ans << endl;
    return 0;
}
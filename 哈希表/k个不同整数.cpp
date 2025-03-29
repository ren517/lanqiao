#include <iostream>
using namespace std;
const int N = 1e5;
int arr[N];
int hasi[N];
int m;
int my_find(int k)
{
    int num = 1;
    int l, r;
    l = r = 1;
    int ans = 0;
    while (l != m)
    {
        if (hasi[r] == 0)
            num++;
        r++;

        while (num > k)
        {
            hasi[arr[l]]--;
            if (hasi[arr[l]] == 0)
            {
                num--;
            }
            l++;
        }
    }
    return ans;
}
int main(void)
{
    int k;
    cin >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        cin >> arr[i];
    }
    cout << my_find(k) << ' ' << my_find(k - 1) << endl;

    return 0;
}
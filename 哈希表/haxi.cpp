#include <iostream>
#include <map>
using namespace std;
int main(void)
{
    int n = 10;
    int ans = 10;
    map<int, int> has;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < n; i++)
    {
        if (has.find(ans - arr[i]) != has.end())
        {
            cout << has[ans - arr[i]] + 1 << ' ' << i + 1 << endl;
        }
        has[arr[i]] = i;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e5;
int arr[N];
vector<int> a[N];
int main(void)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    sort(arr + 1, arr + n + 1);

    for (int i = arr[n]; i >= 1; i--)
    {
        for (int j = 1; j <= n; j++)
        {
            if (arr[j] % i == 0)
            {
                a[i].push_back(arr[j]);
            }
        }
    }
    for (int i = arr[n]; i >= 0; i--)
        if (a[i].size() >= 3)
        {
            for (int k = 0; k < 3; k++)
            {
                cout << a[i][k] << ' ';
            }
            cout << endl;
            break;
        }

    return 0;
}
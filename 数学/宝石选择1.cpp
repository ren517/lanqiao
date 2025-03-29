#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N = 1e5 + 10;
vector<int> G[N];
vector<int> mk[N];
int a[N];
int main(void)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[j] % i == 0)
                mk[i].push_back(a[j]);
        }
    }
    for (int i = N; i >= 1; i--)
    {
        if (mk[i].size() >= 3)
        {
            for (int j = 0; j < 3; j++)
                cout << mk[i][j] << ' ';
            cout << endl;
            break;
        }
    }
    return 0;
}
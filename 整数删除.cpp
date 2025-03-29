#include <iostream>
#include <set>
using namespace std;
set<int> s;
const int N = 10010;
int m = 1e8;
long long arr[N];
bool vir[N];
int main()
{
    // 请在此输入您的代码
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < N; i++)
        arr[i] = m;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        s.insert(arr[i]);
    }
    for (int i = 1; i <= k; i++)
    {
        int temp = *s.begin();
        s.erase(temp);
        cout << temp << endl;
        for (int j = 1; j <= n; j++)
        {
            if (arr[j] == temp)
            {
                s.erase(arr[j - 1]);
                s.erase(arr[j + 1]);
                arr[j - 1] += temp;
                arr[j + 1] += temp;
                arr[j] = m;
                s.insert(arr[j - 1]);
                s.insert(arr[j + 1]);
                vir[j] = true;
                break;
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (arr[i] < m)
            cout << arr[i] << ' ';
    cout << endl;

    return 0;
}
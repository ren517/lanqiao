#include <iostream>
using namespace std;
const int N = 1e6;
int arr[N];
int n, m; // n长度，m操作次数
bool vir(int a, int b)
{
    return a > b;
}
int main()
{
    // 请在此输入您的代码
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        arr[i] = i;
    }
    while (m)
    {
        int a, b;
        cin >> a >> b;
        if (a)
            sort(arr + b, arr + 1 + n);
        else
            sort(arr + 1, arr + b + 1, vir);
        m--;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << ' ';
    }
    cout << endl;
    return 0;
}
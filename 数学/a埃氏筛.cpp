#include <iostream>
using namespace std;
const int N = 1e5;
bool vir[N];
int main(void)
{
    int n;
    cin >> n;
    for (int i = 2; i * i <= n; i++)
    {
        if (!vir[i])
            for (int j = i * i; j <= n; j += i)
            {
                vir[j] = true;
            }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vir[i])
            cout << i << ' ';
    }
    cout << endl;
    return 0;
}
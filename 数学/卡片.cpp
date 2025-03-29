#include <iostream>
using namespace std;
typedef long long ll;
ll n;
int main(void)
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        if (i + ((i - 1) * i) / 2 >= n)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
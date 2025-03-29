#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 1010;
int n;
ll A[N], B[N];

int erfenmax(ll A, ll B)
{
    ll l = 1;
    ll r = A;
    ll mid;
    while (l + 1 != r)
    {
        mid = (l + r) / 2;
        if (A / mid >= B)
            l = mid;
        else
            r = mid;
    }
    return l;
}

int erfenmin(ll A, ll B)
{
    ll l = 1;
    ll r = A;
    ll mid;
    while (l + 1 != r)
    {
        mid = (l + r) / 2;
        if (A / mid <= B)
            r = mid;
        else
            l = mid;
    }
    return r;
}
int main()
{
    // 请在此输入您的代码
    cin >> n;
    ll ansmax[N];
    ll ansmin[N];
    for (int i = 1; i <= n; i++)
    {
        cin >> A[i] >> B[i];
    }
    for (int i = 1; i <= n; i++)
    {
        ansmax[i] = erfenmax(A[i], B[i]);
        ansmin[i] = erfenmin(A[i], B[i]);
    }
    sort(ansmax + 1, ansmax + n + 1);
    sort(ansmin + 1, ansmin + n + 1);
    cout << ansmin[n] << ' ' << ansmax[1] << endl;
    return 0;
}
#include <iostream>
using namespace std;

int main(void)
{
    int w, m, n;
    cin >> w >> m >> n;
    if (m < n)
        swap(m, n);
    int ans = 0;
    int temp1 = (m - 1) / w;
    int temp2 = (n - 1) / w;
    ans += temp1 - temp2;// 记录行的差值
    while (m > w)
    {
        for (int i = 1; i <= temp1 / 2; i++)
            m -= 2 * w;// 每隔两行的差值是2*w
        if (m > w)
            m = m - (m - w - 1) * 2 - 1;// 观察规律，用第二行推出第一行
    }
    while (n > w)
    {
        for (int i = 1; i <= temp2 / 2; i++)
            n -= 2 * w;
        if (n > w)
            n = n - (n - w - 1) * 2 - 1;
    }// 把m和n都转换成小于w的
    ans += abs(m - n);
    cout << m << ' ' << n << endl;
    cout << ans << endl;
    return 0;
}
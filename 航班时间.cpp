#include <iostream>
using namespace std;
const int N = 1e5;
typedef long long ll;
ll temp1[N];
ll temp2[N];

int main(void)
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a1, a2, a3, a4, a5, a6;
        int b1, b2, b3, b4, b5, b6;
        int r = 0;
        scanf("%d:%d:%d %d:%d:%d", &a1, &a2, &a3, &a4, &a5, &a6);
        if (getchar() == ' ')
        {
            scanf("(+%d)", &r);
        }
        int z = ((a4 + r * 24) * 3600 - a1 * 3600) + (a5 - a2) * 60 + a6 - a3;
        r = 0;
        scanf("%d:%d:%d %d:%d:%d", &b1, &b2, &b3, &b4, &b5, &b6);
        if (getchar() == ' ')
        {
            scanf("(+%d)", &r);
        }
        int z1 = ((b4 + r * 24) * 3600 - b1 * 3600) + (b5 - b2) * 60 + b6 - b3;
        temp1[i] = z;
        temp2[i] = z1;
    }
    for (int i = 1; i <= n; i++)
    {
        int ans = (temp1[i] + temp2[i]) / 2;
        printf("%02d:%02d:%02d\n", ans / 3600, ans / 60 % 60, ans % 60);
    }
    return 0;
}
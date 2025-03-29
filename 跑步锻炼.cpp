#include <iostream>
using namespace std;
int main(void)
{
    int ans = 0;
    int x = 6;
    for (int y = 2000; y <= 2020; y++)
    {
        for (int m = 1; m <= 12; m++)
        {
            for (int d = 1; d <= 31; d++)
            {
                if (m == 2)
                {
                    if (y == 2000 || y == 2004 || y == 2008 || y == 2012 || y == 2016 || y == 2020)
                    {
                        if (d > 29)
                            continue;
                    }
                    else if (d > 28)
                        continue;
                }
                if (m == 4 || m == 6 || m == 9 || m == 11)
                    if (d > 30)
                        continue;

                if (x == 1 || d == 1)
                    ans += 2;
                else
                    ans++;
                x++;
                if (x == 8)
                    x = x - 7;
                if (y == 2020 && m == 10 && d == 1)
                    cout << ans;
            }
        }
    }
    // cout << ans + 2 << endl;
    return 0;
}
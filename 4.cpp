#include <iostream>
using namespace std;
int main(void)
{
    int n = 9;
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int len = 1; len <= n; len++)
    {
        for (int l = 1; l + len - 1 <= n; l++)
        {
            int r = l + len - 1;
            for (int k = l; k <= r; k++)
            {
                cout << arr[k] << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}
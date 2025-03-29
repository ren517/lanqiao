#include <iostream>
using namespace std;
int main(void)
{
    int arr[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = 3;
    for (int i = 0; i < 1 << n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (1 & (i >> j))
            {
                cout << arr[j] << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}
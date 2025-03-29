#include <iostream>
using namespace std;
int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int n = 3;
int main(void)
{
    for (int i = 1; i < 1 << n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if ((i >> j) & 1)
                cout << arr[j] << ' ';
        }
        cout << endl;
    }

    return 0;
}
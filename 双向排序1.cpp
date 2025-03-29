#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int arr[N];
bool check(int a, int b)
{
    return a > b;
}
int main(void)
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        arr[i] = i;
    }

    while (k)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        if (temp1 == 0)
            sort(arr + 1, arr + temp2 + 1, check);

        if (temp1 == 1)
            sort(arr + temp2, arr + 1 + n);

        k--;
    }
    for (int i = 1; i <= n; i++)
        cout << arr[i] << ' ';
    cout << endl;

    return 0;
}
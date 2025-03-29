#include <iostream>
using namespace std;

int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int n = 10;
int my_Search(int x)
{
    int l = 0, r = n - 1;
    int mid;
    while (l + 1 != r)
    {
        mid = (l + r) / 2;
        if (x >= arr[mid])
            l = mid;
        else
            r = mid;
    }
    return l;
}
int main(void)
{
    cout << my_Search(5) + 1 << endl;
    return 0;
}
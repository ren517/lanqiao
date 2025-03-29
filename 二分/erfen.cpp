#include <iostream>
using namespace std;
int l, r, n;
int arr[10] = {1, 2, 3, 4, 5, 5, 5, 8, 9, 10};
int my_Search(int x)
{
    l = 0, r = n - 1;
    int mid;
    // while (l + 1 != r)
    // {
    //     mid = (l + r) / 2;
    //     if (x <= arr[mid])
    //         r = mid;
    //     else
    //         l = mid;
    // }
    // return r;找到第一个等于结果的下标
    while (l + 1 != r)
    {
        mid = (l + r) / 2;
        if (x >= arr[mid])
            l = mid;
        else
            r = mid;
    }
    return l; // 找到最后一个等于结果的下标
}
int main(void)
{
    n = 10;

    cout << my_Search(5) + 1 << endl;
    return 0;
}
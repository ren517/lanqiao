#include <iostream>
#include <algorithm>
// #include <vector>
using namespace std;
int main(void)
{
    // vector<int> arr;
    int arr[10] = {1, 2, 2, 2, 3, 4, 5};
    int n = 7;
    auto a = lower_bound(arr, arr + n, 2);// 第一个大于或等于2的下标
    auto b = upper_bound(arr, arr + n, 2);// 第一个大于2的下标

    cout << b - a<< endl;
    return 0;
}
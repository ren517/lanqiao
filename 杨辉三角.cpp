#include <iostream>
#include <algorithm>
using namespace std;
long long arr[10000][10000];
vector<int> s;

int main(void)
{
    int n;
    cin >> n;
    arr[1][1] = 1;
    for (int i = 2; i < 5000; i++)
    {
        for (int j = 2; j < 5000; j++)
        {
            if (i >= j)
            {
                arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1];
                s.push_back(arr[i][j]);
            }
        }
    }
    for (long long i = 0; i < s.size(); i++)
    {
        // cout << s[i] << endl;
        if (s[i] == n)
        {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}
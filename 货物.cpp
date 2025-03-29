#include <iostream>
#include <set>
using namespace std;
long long n = 2021041820210418;
vector<long long> arr;

int main(void)
{
    long long ans = 0;
    for (long long i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            arr.push_back(i);
            arr.push_back(n / i);
            
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr.size(); j++)
        {
            for (int k = 0; k < arr.size(); k++)
            {
                if (arr[i] * arr[j] * arr[k] == n)
                {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
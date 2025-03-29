#include <iostream>
#include <string>
using namespace std;
int main(void)
{
    string s1;
    char a1, a2;
    int k;
    cin >> k;
    cin >> s1 >> a1 >> a2;
    int ans = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (s1[i] == a1)
            for (int j = i + k - 1; j < s1.size(); j++)
            {
                if (s1[j] == a2)
                    ans++;
            }
    }
    cout << ans << endl;
}
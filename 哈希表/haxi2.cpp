#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
int main(void)
{
    string ch = "abcdefghijklmnpqrovwxuyz";
    map<char, int> has;
    for (int i = 0; ch[i]; i++)
    {
        has[ch[i]] = 1;
    }
    for (char i = 'a'; i <= 'z'; i++)
    {
        if (has[i] == 0)
            cout << i << ' ';
    }
    cout << endl;

    return 0;
}
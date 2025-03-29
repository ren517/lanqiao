#include <iostream>
#include <stack>
#include <string>
using namespace std;
int main(void)
{
    stack<char> arr;
    string str;
    cin >> str;
    for (unsigned long i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
        {
            arr.push('(');
        }
        if (str[i] == ')')
        {
            if (arr.empty())
            {
                cout << "NO" << endl;
                return 0;
            }
            arr.pop();
        }
    }
    if (arr.empty())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
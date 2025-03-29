#include <iostream>
#include <stack>
using namespace std;
stack<char> s;
int main(void)
{
    string arr;
    cin >> arr;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == '(')
            s.push('(');
        if (arr[i] == ')')
        {
            if (s.empty())
            {
                cout << "NO" << endl;
                return 0;
            }
            s.pop();
        }
    }

    if (s.empty())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
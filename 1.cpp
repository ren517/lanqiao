#include <iostream>
#include <vector>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int m, n;
    cin >> m >> n;
    vector<vector<char> > ch(n, vector<char>(m + n - 1, '.'));

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < m + i; j++)
        {
            ch[i][j] = '*';
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = m + n - 2 - i; j > n - i - 2; j--)
        {
            ch[i][j] = '*';
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m + n - 1; j++)
        {
            cout << ch[i][j];
        }
        cout << endl;
    }
    return 0;
}
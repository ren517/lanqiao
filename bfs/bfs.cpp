#include <iostream>
#include <string>
using namespace std;

int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy[8] = {1, 1, 1, 0, -1, -1, -1, 0};

int n, m;
string a[1000];

void check(int x, int y)
{
    int num = 0;
    for (int i = 0; i < 8; i++)
    {
        if (x + dx[i] < 0 || x + dx[i] > n - 1)
            continue;
        if (y + dy[i] < 0 || y + dy[i] > n - 1)
            continue;
        else if (a[x + dx[i]][y + dy[i]] == '*')
            num++;
    }
    cout << num;
}
int main(void)
{

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == '*')
                cout << '*';
            if (a[i][j] == '?')
                check(i, j);
        }
        cout << endl;
    }

    return 0;
}
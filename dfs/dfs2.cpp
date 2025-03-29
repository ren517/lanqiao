#include <iostream>
using namespace std;

int arr[100][100];
bool vir[100][100];
int amin = 1e8;
int ans1, ans2;
int n;
void dfs(int x, int y, int dep)
{
    if (x == ans1 && y == ans2)
    {
        if (dep < amin)
        {
            amin = dep;
        }
    }
    if (arr[x][y + 1] == 1 && vir[x + 1][y] == false)
    {
        arr[x][y + 1] = 0;
        vir[x + 1][y] = true;
        dfs(x, y + 1, dep + 1);
        arr[x][y + 1] = 1;
        vir[x][y + 1] = false;
    }
    if (arr[x + 1][y] == 1 && vir[x + 1][y] == false)
    {
        arr[x + 1][y] = 0;
        vir[x + 1][y] = true;
        dfs(x + 1, y, dep + 1);
        arr[x + 1][y] = 1;
        vir[x + 1][y] = false;
    }
    if (arr[x][y - 1] == 1 && vir[x][y - 1] == false)
    {
        arr[x][y - 1] = 0;
        vir[x][y - 1] = true;
        dfs(x, y - 1, dep + 1);
        arr[x][y - 1] = 1;
        vir[x][y - 1] = false;
    }
    if (arr[x - 1][y] == 1 && vir[x - 1][y] == false)
    {
        arr[x - 1][y] = 0;
        vir[x - 1][y] = true;
        dfs(x - 1, y, dep + 1);
        arr[x - 1][y] = 1;
        vir[x - 1][y] = false;
    }
}
int main(void)
{
    int posx, posy;
    int start1, start2;
    cin >> posx >> posy;

    for (int i = 1; i <= posx; i++)
        for (int j = 1; j <= posy; j++)
            cin >> arr[i][j];
    cin >> start1 >> start2 >> ans1 >> ans2;
    dfs(start1, start2, 1);
    cout << amin << endl;
    return 0;
}
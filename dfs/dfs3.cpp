// error
#include <iostream>
using namespace std;

int amin = 1e8;
int arr[100][100];
bool vir[100][100];
int endx, endy;
int fangan = 0;

void dfs(int x, int y, int dep)
{
    if (x == endx && y == endy)
    {
        if (dep < amin)
            amin = dep;
        fangan++;
    }

    if (arr[x][y + 1] == 1 && !vir[x][y + 1])
    {
        vir[x][y + 1] = true;
        arr[x][y + 1] = 1;
        dfs(x, y + 1, dep + 1);
        vir[x][y + 1] = false;
        arr[x][y + 1] = 0;
    }
    if (arr[x + 1][y] == 1 && !vir[x + 1][y])
    {
        vir[x + 1][y] = true;
        arr[x + 1][y] = 1;
        dfs(x + 1, y, dep + 1);
        vir[x + 1][y] = false;
        arr[x + 1][y] = 0;
    }
    if (arr[x][y - 1] == 1 && !vir[x][y - 1])
    {
        vir[x][y - 1] = true;
        arr[x][y - 1] = 1;
        dfs(x, y - 1, dep + 1);
        vir[x][y - 1] = false;
        arr[x][y - 1] = 0;
    }
    if (arr[x - 1][y] == 1 && !vir[x - 1][y])
    {
        vir[x - 1][y] = true;
        arr[x - 1][y] = 1;
        dfs(x - 1, y, dep + 1);
        vir[x - 1][y] = false;
        arr[x - 1][y] = 0;
    }
}
int main(void)
{
    int startx, starty;
    int posx, posy;
    cin >> posx >> posy;
    for (int i = 1; i <= posx; i++)
    {
        for (int j = 1; j <= posy; j++)
        {
            cin >> arr[i][j];
        }
    }
    cin >> startx >> starty >> endx >> endy;
    dfs(startx, starty, 1);
    cout << amin << ' ' << fangan << endl;

    return 0;
}

// 样例
//  5 4
//  1 1 2 1
//  1 1 1 1
//  1 1 2 1
//  1 2 1 1
//  1 1 1 2
//  1 1 4 3
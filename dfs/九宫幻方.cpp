#include <iostream>
using namespace std;
int arr[10];
bool vir[10];
int f = 0;
bool check()
{
    if (arr[1] + arr[2] + arr[3] == 15 && arr[1] + arr[4] + arr[7] == 15 && arr[1] + arr[5] + arr[9] == 15 && arr[2] + arr[5] + arr[8] == 15 && arr[4] + arr[5] + arr[6] == 15 && arr[7] + arr[8] + arr[9] == 15 && arr[3] + arr[6] + arr[9] == 15 && arr[3] + arr[5] + arr[7] == 15)
        return true;

    else
        return false;
}
void dfs(int dep)
{
    if (dep == 10)
    {
        if (check())
        {
            f = 1;
        }
        return;
    }
    if (arr[dep] != 0)
    {
        dfs(dep + 1);
        return;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (vir[i])
            continue;
        vir[i] = true;

        arr[dep] = i;
        dfs(dep + 1);

        if(f)
            return;
        vir[i] = false;
        arr[dep] = 0;
    }
}
int main()
{
    // 请在此输入您的代码
    for (int i = 1; i <= 9; i++)
    {
        cin >> arr[i];
        if (arr[i] != 0)
            vir[arr[i]] = true;
    }
    dfs(1);
    if (!f)
        cout << "Too many" << endl;
    else
        for (int i = 1; i <= 9; i++)
        {
            cout << arr[i] << ' ';
            if (i % 3 == 0)
            {
                cout << endl;
            }
        }

    return 0;
}
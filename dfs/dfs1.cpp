#include <iostream>
using namespace std;

int arr[10] = {1, 3, 5, 7, 9};
int n;
int temp[10];
bool vir[10];
void dfs(int dep)
{
    if (dep == n)
    {
        for (int i = 0; i < n; i++)
            cout << temp[i] << ' ';
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (vir[i])
            continue;
        vir[i] = true;
        temp[dep] = arr[i];
        dfs(dep + 1);
        vir[i] = false;
    }
}
int main(void)
{
    cin >> n;
    dfs(0);
    return 0;
}
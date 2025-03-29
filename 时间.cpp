#include <iostream>
using namespace std;
typedef long long ll;
int main()
{
    // 请在此输入您的代码
    ll time;
    cin >> time;
    time = time / 1000;
    int s = time % 60;
    int m = (time / 60) % 60;
    int h = (time / 60 / 60) % 24;
    printf("%02d:%02d:%02d", h, m, s);
    return 0;
}
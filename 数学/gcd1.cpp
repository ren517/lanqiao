#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    return b > 0 ? (gcd(b, a % b)) : a;
}
int main(void)
{
    cout << gcd(121, 11);
    return 0;
}
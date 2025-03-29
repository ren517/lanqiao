#include <stdio.h>
int main(void)
{
    int num1, num2;
    num1 = num2 = 0;
    scanf("%d", &num1);
    if (getchar() == ' ')
        scanf("%d", &num2);
    printf("%d %d", num1, num2);
    return 0;
}
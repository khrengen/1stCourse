# include <stdio.h>

int main(void)
{
    int c, sum = 0;
    scanf("%d", &c);
    for (int i = 0; i < c; ++i) {
        int a;
        scanf("%d", &a);
        if (a >= 10) {
            sum += a;
        }
    }
    printf("%d\n", sum);
    return (0);
}

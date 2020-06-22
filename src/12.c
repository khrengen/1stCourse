# include <stdio.h>

int rec_func(int a)
{
    if (a == 0) {
        return 0;
    }
    if (a % 10 % 2 == 0) {
        return rec_func(a / 10);
    }
    return rec_func(a / 10) * 10 + a % 10;

}


int main(void)
{
    int a;


    while (scanf("%d", &a) == 1) {

        printf("%d\n", rec_func(a));
    }
    return 0;
}
#include <stdio.h>
int a, b, c;
int main(void)
{
    scanf("%d",&a);
    b=0;
    c=1;
    while (b<16){
        if (((a>>b)&1)&(a>>(31-b)&1)==0) c=0;
        b++;
    }
    if (c==0) printf ("NOT PALINDROM\n");
    if (c==1) printf ("PALINDROM");

    return 0;
}

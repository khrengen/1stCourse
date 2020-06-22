#include <stdio.h>
#include <math.h>

int main(void) {
int a,i,b=0;
	scanf("%d\n",&a);
	int x[a+1];
	for (i = 0; i<=a;i++){
	    scanf("%d\n", &x[i]);
	}



	
    int c = 10,s = 5,q;
    for (q = 1; q<=c; q += 2){

        for (i = 0; i <=a; i++){
        	b += x[a-i] * pow(q,i);
        }
         printf("%d\n", b);	
         b = 0;
    }
   
	return 0; 
}
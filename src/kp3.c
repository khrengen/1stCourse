#include <stdio.h>
#include <math.h>

double eps = 7.0 / 3.0 - 4.0 / 3.0 - 1.0;

double func(double a)
{
	return exp(2 * a);
}

double taylor(double a, double k)
{
	double oldmem = 1.0, newmem = 1.0;
	int n = 1.0;


    while (newmem > eps * k) {
        newmem *= 2 * a / n;
        oldmem += newmem;
        n++;
	}
    return(oldmem);
}

int step(double a)
{
    double newmem = 1.0, k = 1.0;
	int n = 1;

	while (newmem > eps * k) {
        newmem *= 2 * a / n;
        n++;
	}
    return(n);
}
int main(void)
{
	double a = 0.1, b = 0.6, x, k;
	int n;
	scanf("%d%lf\n", &n, &k);
	x = a;
     
	printf("x\t func\t\t\ttaylor\t\t\tsteps\teps\n");

    while (x <= b) {
        printf("%.6f %.20f %.20f\t%d\t%.20f\n", x, func(x), taylor(x, k), step(x), eps * k);
        x += (b - a) / n; 

    }
    return 0;

}
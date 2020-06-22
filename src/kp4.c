#include <stdio.h>
#include <math.h>

double eps = 7.0 / 3.0 - 4.0 / 3.0 - 1.0;
double f1(double x) {
	return(1.0 - x + sin(x) - log(1.0 + x));
}

double f2(double x) {
	return(3.0 * x - 14.0 + exp(x) - exp(-x));
}

double pr1(double x) {
	return(-1.0 + cos(x) - 1.0 / x);
}

double pr2(double x) {
	return(3.0 + exp(x) + exp(-x));
}

double Xx1(double x) {
	return(1.0 + sin(x) - log(x + 1.0));
}

double Xx2(double x) {
	return(log(exp(-x) + 14.0 - 3.0 * x));
}

double DEH(double f(double x), double a, double b) {
	double c;
	while (fabs(a - b) > eps * 2) {
         c = (a + b) / 2.0;
         if (f(a) * f(c) > 0) {
         	a = c;
         } else b = c;
	}
	return c;
}

double IT(double Xx(double x), double a, double b) {
	double x = (a + b) / 2.0;
	double x1 = x + 1.0;
	while(fabs(x1 - x) > eps) {
		x1 = x;
		x = Xx(x);
	}
	return x;
}

double NEW(double f(double x),double pr(double x), double a, double b) {
    double x = (a + b) / 2.0;
    double x1 = x + 1.0;
    while(fabs(x1 - x) > eps) {
    	x1 = x;
    	x = x - f(x) / pr(x);
    }
    return x;

}

int main(void)
{
	printf("DEH\t\t\tIT\t\tNEW\n");	
	printf("%.15f %.15f %.15f\n", DEH(f1, 1.0, 1.5), IT(Xx1, 1.0, 1.5), NEW(f1, pr1, 1.0, 1.5));
	printf("%.15f %.15f %.15f\n", DEH(f2, 1.0, 3.0), IT(Xx2, 1.0, 3.0), NEW(f2, pr2, 1.0, 3.0));
	return 0;
}
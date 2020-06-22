#include <stdio.h>
#include <math.h>


double func(double x)
{
	return exp(x);
}


int main(void)
{
    
   double x =  func(2.0);
	 printf("%.3f", x);
    
}
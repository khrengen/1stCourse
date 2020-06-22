#include <stdio.h>
#include <math.h>
int faq(int n)
{
	int faq = n;
	while (n > 1) {
		n--;
		faq *= n;
		
	}
	return(faq);
}
int main(int argc, char const *argv[])
{
	printf("%d\n", faq(1));
	return 0;
}	
	


#include <stdio.h>

long int factorial (int num)
{
	long int res = 1;
	for (int i = 2; i <= num; i++) {
		res *= i;
	}
	return res;
}

int main (void)
{
	long int var = 0;
	for (int i = 1; i < 100000; i++) {
		var += factorial(i);
	}
	printf("\nit works");
	return 0;
}


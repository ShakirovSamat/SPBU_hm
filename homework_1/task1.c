#include <stdio.h>

float f(float x)
{
	float sqX = x * x;
	return sqX * (sqX + x) + sqX + x + 1;
}

int main ()
{

	printf("This program finds answer for x^4 + x^3 + x^2 + x + 1\n");

	float x = 0;
	printf("Enter x = ");
	scanf_s("%f", &x);
	printf("x^4 + x^3 + x^2 + x = %f \n", f(x));
	return 0;
}
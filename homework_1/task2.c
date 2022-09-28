#include <stdio.h>
#include <stdlib.h>


int main()
{
	int dividend = 0;
	int divisor = 0;
	int quotient = 0;
	int signOfAnswer = 0;

	printf("The program finds the incomplete quotient\nEnter dividend = ");
	scanf_s("%d",&dividend);

	while (divisor == 0)
	{
		printf("Enter divisor = ");
		scanf_s("%d", &divisor);
		if (divisor == 0)
		{
			printf("You can't divide by zero\n");
		}
	}

	if (divisor > 0 == dividend > 0)
	{
		signOfAnswer = 1;
	}
	else
	{
		signOfAnswer = -1;
	}


	if (dividend < 0)
	{
		++quotient;
	}

	dividend = abs(dividend);
	divisor = abs(divisor);
	while (dividend>= divisor)
	{
		dividend -= divisor;
		++quotient;
	}

	printf("The incomplete quotient = %d\n", quotient * signOfAnswer);

	return 0;
	 
}
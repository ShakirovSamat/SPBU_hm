#include <stdio.h>
#include <stdlib.h>

int main()
{
	int dividend = 0;
	int divisor = 0;
	int quotient = 0;

	printf("The program finds the incomplete quotient\nEnter dividend = ");
	scanf_s("%d", &dividend);

	while (divisor == 0)
	{
		printf("Enter divisor = ");
		scanf_s("%d", &divisor);
		if (divisor == 0)
		{
			printf("You can't divide by zero\n");
		}
	}

	int absDividend = abs(dividend);
	int absDivisor = abs(divisor);

	while (absDividend >= absDivisor)
	{
		absDividend -= absDivisor;
		++quotient;
	}

	if (dividend < 0 && absDividend != 0)
	{
		++quotient;
	}

	if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
	{
		quotient = -quotient;
	}
	printf("The incomplete quotient = %d\n", quotient);

	return 0;
}
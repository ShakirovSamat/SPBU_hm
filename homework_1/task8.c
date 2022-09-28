#include <stdio.h>

int main()
{
	int ln = 0;
	int amountOfZero = 0;

	printf("The program counts amount of zero nums in an array\n");
	printf("Enter length of array = ");
	scanf("%d", &ln);



	for(int i = 0; i < ln; ++i){
		int num = 0;
		printf("Enter %d num = ", i + 1);
		scanf_s("%d", &num);
		if (num == 0)
		{
			amountOfZero++;
		}
	}
	
	printf("Amount of zero nums = %d", amountOfZero);
	return 0;
}
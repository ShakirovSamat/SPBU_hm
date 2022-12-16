#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LENGTH 15

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void partition(int array[], int length)
{
	int point = array[0];
	int left = 0;
	int right = length - 1;
	do
	{
		while (array[left] < point)
		{
			left++;
		}
		while (array[right] >= point)
		{
			right--;
		}
		if (left <= right)
		{
			swap(array[left], array[right]);
			left++;
			right--;
		}
	} while (left <= right);
}

int main()
{
	srand(time(0));
	int array[LENGTH] = {0};
	for (int i = 0; i < LENGTH; ++i)
	{
		array[i] = rand();
	}
	printf("Separating element: %d \n", array[0]);
	partition(array, LENGTH);

	for (int i = 0; i < LENGTH; ++i)
	{
		printf("%d ", array[i]);
	}

	return 0;
}
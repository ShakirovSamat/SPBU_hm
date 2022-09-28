#include <stdio.h>
#include <stdlib.h>

#define len 15

void sort(int ar[], int ln)
{
	int point = ar[0];
	int left = 0;
	int right = ln - 1;
	do
	{
		while (ar[left] < point)
		{
			left++;
		}
		while (ar[right] > point)
		{
			right--;
		}
		if (left <= right)
		{
			int temp = ar[left];
			ar[left] = ar[right];
			ar[right] = temp;
			left++;
			right--;
		}
	} while (left <= right);

}
int main()
{
	int arr[len] = { 0 };
	for (int i = 0; i < len; ++i)
	{
		arr[i] = rand();
	}
	printf("%d \n", arr[0]);
	sort(arr, len);

	for (int i = 0; i < len; ++i)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
#include <stdio.h>

void reverse(int *ar, int stIn, int fnIn)
{
	for(int i = 0; i < (fnIn - stIn) / 2; i++)
	{
		int temp = ar[stIn + i];
		ar[stIn + i] = ar[fnIn - i];
		ar[fnIn - i] = temp;
	}

}
int main ()
{
	int changePoint = 0;
	int curPosition = 0;
	int ln = 0;
	int arr[100] = {0};

	printf("The program swaps parts of array length = n. Exemple a = ar[1]..ar[m] and b = ar[m + 1]..ar[n]. Before program it looks like a,b, after it looks like b,a\n");

	//Получаем длину массива от пользователя
	do
	{
	printf("Max size of an array is 100. Enter length of the array = ");
	scanf_s("%d", &ln);
	}
	while (ln > 100);

	//Заполняем массив
	while (curPosition < ln)
	{
		printf("number %d = ",curPosition + 1);
		scanf_s("%d", &arr[curPosition]);
		++curPosition;
	}

	// Получаем индекс, разделяющий массив
	printf("Enter m = ");
	scanf_s("%d", &changePoint);

	reverse(arr, 0, ln - 1);
	reverse(arr, 0, ln - changePoint - 1);
	reverse(arr, ln - changePoint, ln - 1);
	
	//Вывод результата
	printf("Answer = {");
	for(int i = 0; i < ln - 1; ++i)
	{
		printf("%d, ",arr[i]);
	}
	printf("%d}",arr[ln-1]);
	return 0;
}
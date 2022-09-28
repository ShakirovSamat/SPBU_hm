#include <stdio.h>

void reverseArray(int *ar, int startIndex, int finishIndex)
{
	for(int i = 0; i < (finishIndex - startIndex) / 2; i++)
	{
		int temp = ar[startIndex + i];
		ar[startIndex + i] = ar[finishIndex - i];
		ar[finishIndex - i] = temp;
	}

}

int main ()
{
	int changePoint = 0;
	int ln = 0;
	int arr[100] = {0};

	printf("The program swaps parts of array length = n. Exemple a = ar[1]..ar[m] and b = ar[m + 1]..ar[n]. Before program it looks like a,b, after it looks like b,a\n");

	//Получаем длину массива от пользователя
	do
	{
		printf("0 < Length <= 100. Enter length of the array = ");
		scanf_s("%d", &ln);
	} while (0 > ln || ln > 100);

	//Заполняем массив
	for(int i = 0; i < ln; ++i)
	{
		printf("number %d = ", i + 1);
		scanf_s("%d", &arr[i]);
	}

	// Получаем индекс, разделяющий массив
	do
	{
		printf(" 0 <= change point < ln. Enter change point = ");
		scanf_s("%d", &changePoint);
	} while (changePoint < 0 || changePoint > ln);

	reverseArray(arr, 0, ln - 1);
	reverseArray(arr, 0, ln - changePoint - 1);
	reverseArray(arr, ln - changePoint, ln - 1);
	
	//Вывод результата
	printf("Answer = {");
	for(int i = 0; i < ln - 1; ++i)
	{
		printf("%d, ",arr[i]);
	}
	printf("%d}\n",arr[ln-1]);
	return 0;
}
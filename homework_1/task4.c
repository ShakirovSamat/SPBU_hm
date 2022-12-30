#include <stdio.h>

#define maxDigit 9
#define maxSum 28
int main()
{
	int amountOfLuckyTickets = 0;
	int amountOfWays[maxSum] = {0};


	printf("The program counts amount of lucky tikets\n");


	// Подсчитываем кол-во спсобов получить суммы от 0 до 27
	for(int i = 0; i <= maxDigit; ++i)
	{
		for(int j = 0; j <= maxDigit; ++j)
		{
			for(int k = 0; k <= maxDigit; ++k)
			{
				++amountOfWays[i + j + k];
			}
		}
	}
	// Считаем количество счастливых билетов и выводим в консоль
	for(int i = 0; i < maxSum; ++i)
	{
			amountOfLuckyTickets += amountOfWays[i] * amountOfWays[i];
	}
	printf("Amount of lucky tickets = %d\n", amountOfLuckyTickets);
	return 0;
}
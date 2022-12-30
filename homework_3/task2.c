#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quickSort.h"

int binSearch(int *array, int length, int target)
{
    int left = -1;
    int right = length;
    while (left < right - 1)
    {
        int middle = (left + right) / 2;
        if (array[middle] > target)
        {
            right = middle;
        }
        else
        {
            left = middle;
        }
    }

    if (left == -1)
    {
        return array[0] == target;
    }

    return array[left] == target;
}

int main()
{
    srand(time(NULL));

    int length = 0;
    printf("Enter the length of the array: ");
    scanf("%d", &length);
    if (length <= 0)
    {
        printf("Wrong input: the length should be positive");
        return -1;
    }

    int amountOfRandomNumbers = 0;
    printf("Enter amount of the random numbers: ");
    scanf("%d", &amountOfRandomNumbers);
    if (amountOfRandomNumbers <= 0)
    {
        printf("Wrong input: amount of the random numbers should be positive");
        return -1;
    }

    int *array = calloc(length, sizeof(int));
    if (array == NULL)
    {
        printf("Memory error");
        return -1;
    }

    for (int i = 0; i < length; i++)
    {
        array[i] = rand();
    }

    quickSort(array, 0, length - 1);

    for (int i = 0; i < amountOfRandomNumbers; i++)
    {
        int target = rand();
        if (binSearch(array, length, target))
        {
            printf("%d was found in array\n", target);
        }
        else
        {
            printf("%d wasn't found in array\n", target);
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include "quickSort.h"

int mostCommon(int array[], int length)
{
    int maxFrequency = 1;
    int mostCommon = array[0];
    int counter = 1;
    for (int i = 1; i < length; i++)
    {
        if (array[i - 1] == array[i])
        {
            counter++;
        }
        else if (counter > mostCommon)
        {
            mostCommon = array[i - 1];
            maxFrequency = counter;
            counter = 1;
        }
    }
    return mostCommon;
}

int main()
{
    int length = 0;
    printf("Enter the length of the array: ");
    scanf("%d", &length);
    if (length <= 0)
    {
        printf("Wrong input: the length should be positive");
        return -1;
    }

    int *array = calloc(length, sizeof(int));
    if (array == NULL)
    {
        printf("Memory error");
        return -1;
    }

    printf("Enter number:\n");
    for (int i = 0; i < length; ++i)
    {
        printf("%d: ", (i + 1));
        scanf("%d \n", &array[i]);
    }
    printf("\n");

    quickSort(array, 0, length - 1);

    int mstCommon = mostCommon(array, length);
    printf("Most common number is %d", mstCommon);
    return 0;
}
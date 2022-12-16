#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "sorts.h"

bool test()
{
    int nums[10] = {5, 6, 1, 2, 3, 9, 7, 8, 4, 10};
    quickSort(nums, 0, 9);
    for (int i = 0; i < 9; ++i)
    {
        if (nums[i] > nums[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    if (!test())
    {
        return -1;
    }

    FILE *file = fopen("nums.txt", "r");
    if (file == NULL)
    {
        return -1;
    }

    int length = 0;
    fscanf(file, "%d", &length);
    if (length <= 0)
    {
        printf("Wrong length of the array");
        fclose(file);
        return -1;
    }
    int *array = (int *)calloc(length, sizeof(int));

    for (int i = 0; i < length; ++i)
    {
        fscanf(file, "%d", &array[i]);
    }

    quickSort(array, 0, length - 1);

    int mostCommon = array[0];
    int max = 1;
    int counter = 1;
    for (int i = 1; i < length; i++)
    {
        if (array[i - 1] == array[i])
        {
            counter++;
        }
        else if (counter > max)
        {
            max = counter;
            mostCommon = array[i - 1];
            counter = 1;
        }
    }
    printf("Most common number is %d. It appears %d times", mostCommon, max);
    printf("\n");
    fclose(file);
    return 0;
}
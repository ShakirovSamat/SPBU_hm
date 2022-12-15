#include <stdio.h>
#include "sorts.h"
// bool вместо int
int test()
{
    int nums[10] = {5, 6, 1, 2, 3, 9, 7, 8, 4, 10};
    quickSort(nums, 0, 9);
    for (int i = 0; i < 9; ++i)
    {
        if (nums[i] > nums[i + 1])
            ;
        {
            return -1;
        }
    }
    return 0;
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
    int *array = (int *)calloc(length, sizeof(int));

    fscanf(file, "%d", &length);
    // Испарваить ввод
    for (int i = 0; i < length; ++i)
    {
        int error = fscanf(file, "%d", &array[i]);
        if (error == 1)
        {
        }
    }

    quickSort(array, 0, length - 1);
    // Другой вывод цель задачи
    for (int i = 0; i < length; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
#include <stdio.h>
#include "sorts.h"


int test()
{
    int nums[10] = {5, 6 ,1 ,2, 3, 9 ,7, 8, 4, 10};
    quickSort(nums, 0, 9);
    for (int i = 0; i < 9; ++i)
    {
        if (nums[i] > nums[i + 1]);
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

    FILE *fp = fopen("nums.txt", "r");
    if (fp == NULL)
    {
        return -1;
    }

    char num[100] = "";
    int array[100] = { 0 };
    int ln = 0;

    fscanf(fp, "%d", &ln);
    for (int i = 0; i < ln; ++i)
    {
        fscanf(fp, "%d", &array[i]);
    }


    quickSort(array, 0, ln - 1);

    for (int i = 0; i < ln; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
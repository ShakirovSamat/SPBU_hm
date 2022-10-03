#include <stdio.h>
#include "sorts.h"


int main()
{
    FILE *fp = fopen("nums.txt", "r");
    if (fp == NULL)
    {
        return 1;
    }

    char num[100] = "";
    int array[100] = { 0 };
    int ln = 0;

    fscanf(fp, "%d", &ln);
    for(int i = 0; i < ln; ++i)
    {
        fscanf(fp, "%d", &array[i]);
    }


    quickSort(array, 0, ln - 1);

    for(int i = 0; i < ln; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}
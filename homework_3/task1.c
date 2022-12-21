#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

void insertSort(int array[], int length, int start)
{
    for (int i = start; i < start + length; ++i)
    {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key)
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

int partition(int *array, int start, int end)
{
    int temp = 0;
    int marker = start;
    for (int i = start; i < end; i++)
    {
        if (array[i] < array[end])
        {
            temp = array[marker];
            array[marker] = array[i];
            array[i] = temp;
            marker += 1;
        }
    }

    temp = array[marker];
    array[marker] = array[end];
    array[end] = temp;
    return marker;
}

void quickSort(int *array, int start, int end)
{
    if (end - start > 9)
    {
        if (start >= end)
        {
            return;
        }
        int pivot = partition(array, start, end);

        quickSort(array, start, pivot - 1);
        quickSort(array, pivot + 1, end);
    }
    else
    {
        insertSort(array, end - start + 1, start);
    }
}

int main()
{
    int length = 0;
    printf("Enter the length of the array: ");
    scanf("%d", &length);
    if (length <= 0)
    {
        printf("Wrong input: length should be positive");
        return -1;
    }

    int *array = calloc(length, sizeof(int));
    if (array == NULL)
    {
        printf("Memory error");
        return -1;
    }

    printf("Enter numbers:\n");
    for (int i = 0; i < length; ++i)
    {
        printf("%d: ", i + 1);
        scanf("%d", &array[i]);
    }

    quickSort(array, 0, length - 1);

    printf("Sorted array: ");
    for (int i = 0; i < length; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n\n");

    return 0;
}
#include <stdio.h>
#include <stddef.h>


int selectionSort(int *array, int len)
{
    if (array == NULL)
    {
        return -1;
    }
    for (int i = 0; i < len; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < len; ++j)
        {
            if (array[minIndex] > array[j])
            {
                minIndex = j;
            }
        }
        int temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;
    }
    return 0;
}

int testSelectionSort()
{
    int arrays[4][7] = {{1, 2, 3, 4, 5, 6, 7}, {7, 6, 5, 4, 3, 2, 1}, {5, 1, 2, 7, 4, 3, 6}, {1, 1, 1, 2, 3, 2, 2}};
    for (int i = 0; i < 4; ++i)
    {
        selectionSort(arrays[i], 7);
        for(int j = 0; j < 6; ++j)
        {
            if (arrays[i][j] > arrays[i][j + 1])
            {
                printf("SelectionSort Error");
                return -1;
            }
        }
    }
    return 0; 
}

int main()
{
    testSelectionSort();
    return 0;
}
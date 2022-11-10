#include <stdbool.h>
#include <stdlib.h>

typedef int Error;

bool correct(int *array, int len)
{
    for(int i = 0; i < len - 1; ++i)
    {
        if (array[i] > array[i + 1])
        {
            return false;
        }
    }
    return true;
}

Error swap(int *array, int indexFirst, int indexSecond)
{
    if (array == NULL)
    {
        return -1;
    }

    int temp = array[indexFirst];
    array[indexFirst] = array[indexSecond];
    array[indexSecond] = temp;
    return 0; 
}

Error randomSort(int *array, int len)
{
    if (array == NULL)
    {
        return -1;
    }

    for (int i = 0; i < len; ++i)
    {
        swap(array, i, rand() % len);
    }

    return 0;
}

Error bogoSort(int *array, int len)
{
    if (array == NULL)
    {
        return -1;
    }
    while (!correct(array, len))
    {
        randomSort(array, len);
    }
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "bogosort.h"

int main()
{
    int len = 0;
    int *array = NULL;
    do
    {
        printf("Enter len. len > 0: ");
        scanf("%d", &len);
    } while (len <= 0);

    array = malloc(sizeof(int) * len);

    if (array == NULL)
    {
        return -1;
    }

    for (int i = 0; i < len; ++i)
    {
        printf("Enter %d number: ", i + 1);
        scanf("%d", &array[i]);
    }

    bogoSort(array, len);

    for (int i = 0; i < len; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    
    return 0;
}
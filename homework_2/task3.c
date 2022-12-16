#include <stdio.h>

#define RANGE 20000
#define MAX_LENGTH 100

void bubbleSort(int array[], int length)
{
    for (int i = 1; i < length; ++i)
    {
        for (int j = 0; j < length - i; ++j)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
            }
        }
    }
}

void countingSort(int array[], int length)
{
    int pos = 0;
    int holder[RANGE] = {0};
    for (int i = 0; i < length; ++i)
    {
        ++holder[array[i] + RANGE / 2];
    }
    for (int i = 0; i < RANGE; ++i)
    {
        for (int j = 0; j < holder[i]; ++j)
        {
            array[pos] = i - RANGE / 2;
            pos++;
        }
    }
}

void arrOut(int ar[], int ln)
{
    for (int i = 0; i < ln; i++)
    {
        printf("%d ", ar[i]);
    }
    printf("\n");
}

int main()
{
    int arrBubble[MAX_LENGTH] = {0};
    int arrCounting[MAX_LENGTH] = {0};
    int length = 0;
    while (length <= 0 || length > MAX_LENGTH)
    {
        printf("Max length of an array is %d and each array element should be between -10000 and 10000.\nEnter length = ", MAX_LENGTH);
        scanf_s("%d", &length);
    }
    for (int i = 0; i < length; ++i)
    {
        printf("Enter number №%d= ", i + 1);
        scanf("%d", &arrBubble[i]);
        arrCounting[i] = arrBubble[i];
    }

    bubbleSort(arrBubble, length);
    arrOut(arrBubble, length);

    countingSort(arrCounting, length);
    arrOut(arrCounting, length);

    return 0;
}
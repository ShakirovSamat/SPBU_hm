#include <stdio.h>

#define range 20000
#define ar_ln 100


void bubbleSort(int ar[], int ln)
{
    for (int i = 1; i < ln; ++i)
    {
        for (int j = 0; j < ln - i; ++j)
        {
            if (ar[j] > ar[j + 1]) 
            {
                int temp = ar[j + 1];
                ar[j + 1] = ar[j];
                ar[j] = temp;
            } 
        }
    }
}

void countingSort(int ar[], int ln)
{
    int pos = 0;
    int holder[range] = {0};
    for (int i = 0; i < ln; ++i)
    {
        holder[ar[i] + range / 2] += 1;
    }
    for (int i = 0; i < range; ++i)
    {
        for (int j = 0; j < holder[i]; ++j)
        {
            ar[pos] = i - range / 2;
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
    int arrBubble[ar_ln] = {0};
    int arrCounting[ar_ln] = {0};
    int ln = 0;
    while (ln <= 0 || ln > ar_ln)
    {
        printf("Max length is %d and num should be -10000 <= num <= 10000. Enter length = ", ar_ln);
        scanf_s("%d", &ln);
    }
    for (int i = 0; i < ln; ++i)
    {
        printf("Enter %d number = ", i + 1);
        scanf("%d", &arrBubble[i]);
        arrCounting[i] = arrBubble[i];
    }

    bubbleSort(arrBubble, ln);
    arrOut(arrBubble, ln);

    countingSort(arrCounting, ln);
    arrOut(arrCounting, ln);


    return 0;
}
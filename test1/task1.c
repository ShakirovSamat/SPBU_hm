#include <stdio.h>

int insertSort(int *ar, int size)
{
    for(int i = 0; i < size; i++)
    {
        if (ar[i] % 2 == 0)
        {
            int key = ar[i];
            int j = i - 1;
            int inlast = i;
            while ((ar[j] > key || ar[j] % 2 == 1) && j >= 0)
            {
                if (ar[j] % 2 == 0)
                {
                    ar[inlast] = ar[j];
                    inlast = j;
                }
                j--;
            }
            ar[inlast] = key;
        }
    }

}

int test()
{
    int array[10] = {4, 1, 2, 5, 3, 8, 9 ,10, 7, 6};
    insertSort(array, 10);
    int last = 0;
    int cur = 0;
    for(int i = 0; i < 10; ++i)
    {
        if(array[i] % 2 == 0)
        {
            last = cur;
            cur = array[i];
            if (last > cur)
            {
                return 1;
            }
        }
    }
    for(int i = 0; i < 10; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}

int main()
{
    if (test() == 1)
    {
        printf("Program works incorrectly\n");
    }
    else{
        printf("Program works correctly\n");
    }

    int array[100] = {0};
    int ln = 0;
    while (1 > ln || ln > 100)
    {
        scanf("%d", &ln);
    }
    for(int i = 0; i < ln; i++)
    {
        scanf("%d", &array[i]);
    }
    
    insertSort(array, ln);

    for(int i = 0; i < ln; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}
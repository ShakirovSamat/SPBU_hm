#include <stdio.h>
#include <stdlib.h>
#define arrLn 1000
void quickSort(int *ar, int first, int last)
{
    if (first < last)
    {
        int left = first;
        int right = last;
        int middle = ar[(first + last) / 2];
        do
        {
            while (ar[left] < middle)
            {
                left++;
            }
            while (ar[right] > middle)
            {
                right--;
            }
            if (left <= right)
            {
                int temp = ar[left];
                ar[left] = ar[right];
                ar[right] = temp;
                left++;
                right--;
            }
        } while (left <= right);

        quickSort(ar, first, right);
        quickSort(ar, left, last);
    }
}

int binSearch(int *ar, int ln, int target)
{
    int left = -1;
    int right = ln;
    while (left < right - 1)
    {
        int mid = (left + right) / 2;
        if (ar[mid] > target)
        {
           right = mid;
        }
        else
        {
            left = mid;
        }
    }
    return ar[left] == target;
}

int main()
{
    int ln = 0;
    int numbers = 0;
    int array[arrLn] = {0};
    
    printf("Enter k = ");
    scanf("%d", &numbers);
    printf("Enter m <= 1000 = ");
    scanf("%d", &ln);

    for(int i = 0; i < ln; i++)
    {
        array[i] = rand();
    }

    quickSort(array, 0, ln - 1);

    for(int i = 0; i < numbers; i++)
    {
        int target = rand();
        if (binSearch(array, ln, target))
        {
            printf("%d was found in array\n", target);
        }
        else{
            printf("%d wasn't found in array\n", target);
        }
        
        
    }
    return 0;
}
#include <stdio.h>

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
int main()
{
    int arr[30] = {1, 2, 3, 7 ,8 ,7 , 4, 5, 6 , 10, 11, 20, 19 , 18, 12, 13, 7 ,16, 14, 15, 7, 41, 15, 413, 44, 43, 31, 15, 553, 22};
    quickSort(arr, 0, 29);
    int mostCommon = 0;
    int max = 1;
    int counter = 1;
    for(int i = 1; i < 30; i++)
    {
        if (arr[i - 1] == arr[i])
        {
            counter++;
        }
        else if (counter > max)
        {
            max = counter;
            mostCommon = arr[i - 1];
            counter = 1;
        }
    }
    printf("Most common number is %d. It appears %d times", mostCommon, max);
    return 0;
}
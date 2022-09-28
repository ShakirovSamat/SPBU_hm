#include <stdio.h>


void insertSort(int ar[], int ln, int st)
{
    for(int i = st; i < st + ln; ++i)
    {
        int key = ar[i];
        int j = i - 1;
        while (j >= 0 && ar[j] > key)
        {
            ar[j + 1] = ar[j];
            --j;
        }
        ar[j + 1] = key;
    }
}

void quickSort(int *ar, int first, int last)
{
    if (last - first > 9){
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
    else{
        insertSort(ar, last - first + 1, first);
    }
   
}



int main()
{
    int arr[30] = {1, 2, 3, 9 ,8 ,7 , 4, 5, 6 , 10, 11, 20, 19 , 18, 12, 13, 17 ,16, 14, 15, 103, 41, 124, 413, 44, 43, 31, 15, 553, 22};

    quickSort(arr, 0, 29);
    for(int i = 0; i < 30; ++i)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
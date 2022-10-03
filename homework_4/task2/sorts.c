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
int partition(int *array, int left, int right)
{
    int middle = array[(left + right) / 2];
    do
    {
        while (array[left] < middle)
        {
            left++;
        }
        while (array[right] > middle)
        {
            right--;
        }
        if (left <= right)
        {
            int temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            left++;
            right--;
        }
    } while (left <= right);
    return right;
}

void quickSort(int *array, int first, int last)
{
    if (first < last)
    {
        // вынести отдельно
        int pivot = partition(array, first, last);
        quickSort(array, first, pivot);
        quickSort(array, pivot - 1, last);
    }
}
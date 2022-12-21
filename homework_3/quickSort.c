int partition(int *array, int start, int end)
{
    int temp = 0;
    int marker = start;
    for (int i = start; i < end; i++)
    {
        if (array[i] < array[end])
        {
            temp = array[marker];
            array[marker] = array[i];
            array[i] = temp;
            marker += 1;
        }
    }

    temp = array[marker];
    array[marker] = array[end];
    array[end] = temp;
    return marker;
}

void quickSort(int *array, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int pivot = partition(array, start, end);

    quickSort(array, start, pivot - 1);
    quickSort(array, pivot + 1, end);
}
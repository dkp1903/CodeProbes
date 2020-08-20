void merge(vector<int> &a, int start, int mid, int end)
{
    int i, j, k;
    int size1 = mid - start + 1; // array1 if from [start, mid]
    int size2 = end - mid; // array2 is from [mid + 1, end]

    int left_array[size1], right_array[size2];

    for(i = 0 ; i < size1; i++)
        left_array[i] = a[start + i];
    for(j = 0 ; j < size2; j++)
        right_array[j] = a[mid + 1 + j];

    // Now doing the sorted merge

    // Note that our array a, that we passed in, that we have to fill, 
    // starts NOT at 0, but at start. 
    // So, k = start.
    i = 0, j = 0, k = start; 

    while (i < size1 && j < size2)
    {
        if(left_array[i] < right_array[j])
            a[k++] = left_array[i++];
        else
            a[k++] = right_array[j++];
    }

    // Now, completing the remaining elements.
    // Note that elements will be remaining in ONLY ONE of the two, and all the elements will 
    // be greater than the elements in a, so far.
    while (i < size1)
        a[k++] = left_array[i++];

    while (j < size2)
        a[k++] = right_array[j++];

}

void merge_sort(vector<int> &a, int start, int end)
{
    
    if(start >= end)
        return;
    int mid = (start + end)/2;

    merge_sort(a, start, mid);
    merge_sort(a, mid + 1, end);

    merge(a, start, mid, end);
}

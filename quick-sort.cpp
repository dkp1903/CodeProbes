int pivot(vector<int>a, int start, int end)
{
	int i = start + 1, j = start + 1;
  	int piv = start;
  
  	while(j <= end)
    {
    	if (a[j] < a[piv])
        {
        	swap(a[j], a[i]);
          	i++;
        }
      	j++;
    
    }
  	swap(a[piv], a[i-1]);
  	return (i-1);
}

void quick_sort(vector<int>a, int start, int end)
{
    if(start >= end)
        return;
    int piv = pivot(a, start, end);
    quick_sort(a, start, piv - 1);
    quick_sort(a, piv + 1, end);
}

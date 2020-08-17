    #define vi vector<int>
    int transitionPoint(vi a, int n) {
        if(a[n-1] == 0)
            return -1;
        if (a[0] == 1)
            return 0;
        int low = 0;
        int high = n - 1;
        int mid = (low + (high - low)/2);

        while (low <= high)
        {
            mid = (low + (high - low)/2);
            if (a[mid] == 1 && a[mid - 1] == 0)
                return mid;
            else if (a[mid] == 0)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

#define vi vector<int>
vector <int> countDistinct (vi A, int n, int k)
{
    map<int, int>m;
    int count = 0;
    vector<int>ans;
    
    //Checking First k elements
    for (int i = 0; i < k ; i++)
    {
        if (m[A[i]] == 0)
            count++;
        m[A[i]]++;
    }
    ans.push_back(count);
    
    // Rest of the elements
    for(int i = k ; i < n ; i++)
    {
        if (m[A[i - k]] == 1)
            count--;
        m[A[i - k]]--;
        
        if (m[A[i]] == 0)
            count++;
        m[A[i]]++;
        
        ans.push_back(count);
    }
    return ans;
}

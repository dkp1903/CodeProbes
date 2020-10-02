//sliding window approach
int shortestSubarray(vector<int>& a, int k) {
        int n=a.size();
        if(n==0)
            return -1;
        if(n==1 && k!=a[0]) 
            return -1;
        deque<int> d;
        int p[n+1];
        memset(p,0,sizeof(p));
        for(int i=0;i<n;i++)
        {
            p[i+1]=p[i]+a[i];
        }
        int ans=n+1;
        for(int i=0;i<n+1;i++)
        {
            while(!d.empty() && p[i]<=p[d.back()])
            {
                d.pop_back();
            }
            while(!d.empty() && p[i] >= p[d.front()]+k)
            { 
                ans=min(ans, i-d.front());
                d.pop_front();
            }
            d.push_back(i);
        }
        if(ans<n+1)
            return ans;
        return -1;
    }

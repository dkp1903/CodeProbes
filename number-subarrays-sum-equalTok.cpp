#include<bits/stdc++.h>
using namespace std;

vector<int> v;

int CountSumk(vector<int> &v,int size,int k)
{
    unordered_map<int,int> prev;
    int ans=0,sum=0;

    for(int i=0;i<size;i++)
    {
        sum+= v[i];

        //if the current sum becomes equal to k then increment ans by 1;
        if(sum==k) ans++;

        //if sum-k is already encounterd before than add that to the ans
        if(prev.count(sum-k))
        {
            ans+= prev[sum-k];
        }

       // this will keep track for how many number of times the sum is present in the given array.
        prev[sum]++;
    }

    return ans;
}



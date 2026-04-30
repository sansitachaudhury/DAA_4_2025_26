//Question: (LIS) Given an integer array nums, return the length of the longest strictly increasing subsequence.
#include <iostream>
using namespace std;

int lenOfLIS(int nums[],int n)
{
    int dp[n];
    for (int i=0;i<n;i++)
        dp[i]=1;
    for (int i=1;i<n;i++)
    {
        for(int j=0; j<i;j++)
        {
            if(nums[i]>nums[j])
                dp[i] = max(dp[i], dp[j]+1);
        }
    }
    int ans=0;
    for (int i=0;i<n;i++)
        ans=max(ans, dp[i]);
    return ans;
}
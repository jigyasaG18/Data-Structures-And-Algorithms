Partition Array for Maximum Sum
Given an integer array arr, partition the array into (contiguous) subarrays of length at most k. After partitioning, each subarray has their values changed to become the maximum value of that subarray.
Return the largest sum of the given array after partitioning. Test cases are generated so that the answer fits in a 32-bit integer.

Example 1:
Input: arr = [1,15,7,9,2,5,10], k = 3
Output: 84
Explanation: arr becomes [15,15,15,9,10,10,10]

Example 2:
Input: arr = [1,4,1,5,7,3,6,1,9,9,3], k = 4
Output: 83

Example 3:
Input: arr = [1], k = 1
Output: 1

1st Way:- MEMOIZATION
class Solution {
    public:
    int func(int ind,vector<int>&arr,int k,vector<int>&dp){
        int n=arr.size();
        if(ind==n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int maxans=INT_MIN;
        int maxi=INT_MIN;
        int len=0;
        for(int j=ind;j<min(ind+k,n);j++){
            len++;
            maxi=max(maxi,arr[j]);
            int sum=(len*maxi)+func(j+1,arr,k,dp);
            maxans=max(maxans,sum);
        }
        return dp[ind]=maxans;
    }
        int maxSumAfterPartitioning(vector<int>& arr, int k) {
            int n=arr.size();
            vector<int>dp(n,-1);
            return func(0,arr,k,dp);
        }
    };

2nd Way:- TABULATION
class Solution {
    public:
        int maxSumAfterPartitioning(vector<int>& arr, int k) {
            int n=arr.size();
            vector<int>dp(n+1,0);
            for(int ind=n-1;ind>=0;ind--){
                int maxans=INT_MIN;
        int maxi=INT_MIN;
        int len=0;
        for(int j=ind;j<min(ind+k,n);j++){
            len++;
            maxi=max(maxi,arr[j]);
            int sum=(len*maxi)+dp[j+1];
            maxans=max(maxans,sum);
        }
        dp[ind]=maxans;
            }
            return dp[0];
        }
    };
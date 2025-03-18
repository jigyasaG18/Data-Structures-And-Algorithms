Count Subsets with Sum K / Perfect Sum Problem
Given an array arr of non-negative integers and an integer target, the task is to count all subsets of the array whose sum is equal to the given target.

Examples:
Input: arr[] = [5, 2, 3, 10, 6, 8], target = 10
Output: 3
Explanation: The subsets {5, 2, 3}, {2, 8}, and {10} sum up to the target 10.

Input: arr[] = [2, 5, 1, 4, 3], target = 10
Output: 3
Explanation: The subsets {2, 1, 4, 3}, {5, 1, 4}, and {2, 5, 3} sum up to the target 10.

Input: arr[] = [5, 7, 8], target = 3
Output: 0
Explanation: There are no subsets of the array that sum up to the target 3.

Input: arr[] = [35, 2, 8, 22], target = 0
Output: 1
Explanation: The empty subset is the only subset with a sum of 0.

1st Way:- MEMOIZATION
class Solution {
    public:
    int func(vector<int>& arr,int target,int ind,vector<vector<int>>& dp){
        if(ind==0){
            if(target==0 && arr[0]==0) return 2;
            if(target==0 || arr[0]==target) return 1;
            return 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int not_take=func(arr,target,ind-1,dp);
        int take=0;
        if(arr[ind]<=target) take=func(arr,target-arr[ind],ind-1,dp);
        return dp[ind][target]=take+not_take;
    }
      int perfectSum(vector<int>& arr, int target) {
          // code here
          int n=arr.size();
          vector<vector<int>>dp(n,vector<int>(target+1,-1));
          return func(arr,target,n-1,dp);
      }
  };

2nd Way:- TABULATION
class Solution {
    public:
      int perfectSum(vector<int>& arr, int target) {
          // code here
          int n=arr.size();
          vector<vector<int>>dp(n,vector<int>(target+1,0));
          if(arr[0]==0) dp[0][0]=2;
          else dp[0][0]=1;
          if(arr[0]!=0 && arr[0]<=target) dp[0][arr[0]]=1;
          
          for(int ind=1;ind<n;ind++){
              for(int sum=0;sum<=target;sum++){
                  int not_take=dp[ind-1][sum];
                  int take=0;
                  if(arr[ind]<=sum) take=dp[ind-1][sum-arr[ind]];
                  dp[ind][sum]=not_take+take;
              }
          }
          return dp[n-1][target];
      }
  };

3rd Way:- SPACE OPTIMISATION
class Solution {
    public:
      int perfectSum(vector<int>& arr, int target) {
          // code here
          int n=arr.size();
          vector<int>prev(target+1,0),curr(target+1,0);
          prev[0]=curr[0]=1;
          if(arr[0]==0) prev[0]=2;
          else prev[0]=1;
          if(arr[0]!=0 && arr[0]<=target) prev[arr[0]]=1;
          
          for(int ind=1;ind<n;ind++){
              for(int sum=0;sum<=target;sum++){
                  int not_take=prev[sum];
                  int take=0;
                  if(arr[ind]<=sum) take=prev[sum-arr[ind]];
                  curr[sum]=not_take+take;
              }
              prev=curr;
          }
          return prev[target];
      }
  };
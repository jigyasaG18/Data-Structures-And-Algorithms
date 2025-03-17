Subset Sum Problem
Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum. 

Examples:
Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
Output: true 
Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.

Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
Output: false
Explanation: There is no subset with target sum 30.

Input: arr[] = [1, 2, 3], sum = 6
Output: true
Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.

1st Way:- MEMOIZATION
class Solution {
    public:
    bool solve(int ind,int target,vector<int>&arr,vector<vector<int>>&dp){
        if(target==0) return true;
        if(ind==0) return (arr[0]==target);
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool not_take=solve(ind-1,target,arr,dp);
        bool take=false;
        if(arr[ind]<=target) take = solve(ind-1,target-arr[ind],arr,dp);
        return dp[ind][target]=take || not_take;
    }
      bool isSubsetSum(vector<int>& arr, int sum) {
          // code here
          int n=arr.size();
          vector<vector<int>>dp(n,vector<int>(sum+1,-1));
          return solve(n-1,sum,arr,dp);
      }
  };

2nd Way:- TABULATION
class Solution {
    public:
      bool isSubsetSum(vector<int>& arr, int sum) {
          // code here
          int n=arr.size();
          vector<vector<bool>>dp(n,vector<bool>(sum+1,false));
          for(int i=0;i<n;i++){
              dp[i][0]=true;
          }
          if(arr[0]<=sum){
              dp[0][arr[0]]=true;
          }
          for(int ind=1;ind<n;ind++){
              for(int target=1;target<=sum;target++){
                  bool not_take=dp[ind-1][target];
                  bool take=false;
                  if(arr[ind]<=target) take=dp[ind-1][target-arr[ind]];
                  dp[ind][target]=take||not_take;
              }
          }
          return dp[n-1][sum];
      }
  };

3rd Way:- SPACE OPTIMIZATION
class Solution {
    public:
      bool isSubsetSum(vector<int>& arr, int sum) {
          // code here
          int n=arr.size();
          vector<bool>prev(sum+1,0),curr(sum+1,0);
          prev[0]=curr[0]=true;
          prev[arr[0]]=true;
          for(int ind=1;ind<n;ind++){
              for(int target=1;target<=sum;target++){
                  bool not_take=prev[target];
                  bool take=false;
                  if(arr[ind]<=target) take=prev[target-arr[ind]];
                  curr[target]=take||not_take;
              }
              prev=curr;
          }
          return prev[sum];
      }
  };
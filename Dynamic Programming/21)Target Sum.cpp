Target Sum 
You are given an integer array nums and an integer target.
You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.
For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Example 1:
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Example 2:
Input: nums = [1], target = 1
Output: 1

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
          return dp[ind][target]=(take+not_take);
      }
        int perfectSum(vector<int>& arr, int target) {
            // code here
            int n=arr.size();
            vector<vector<int>>dp(n,vector<int>(target+1,-1));
            return func(arr,target,n-1,dp);
        }
        int countPartitions(vector<int>& arr, int d) {
            // Code here
            int totsum=0;
            for(auto &it : arr) totsum+=it;
            if(totsum - d <0 || (totsum-d)%2) return false;
            return perfectSum(arr,(totsum-d)/2);
        }
        int findTargetSumWays(vector<int>& nums, int target) {
            return countPartitions(nums,target);
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
                    dp[ind][sum]=(not_take+take);
                }
            }
            return dp[n-1][target];
        }
        int countPartitions(vector<int>& arr, int d) {
            // Code here
            int totsum=0;
            for(auto &it : arr) totsum+=it;
            if(totsum - d <0 || (totsum-d)%2) return false;
            return perfectSum(arr,(totsum-d)/2);
        }
        int findTargetSumWays(vector<int>& nums, int target) {
            return countPartitions(nums,target);
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
                    curr[sum]=(not_take+take);
                }
                prev=curr;
            }
            return prev[target];
        }
        int countPartitions(vector<int>& arr, int d) {
            // Code here
            int totsum=0;
            for(auto &it : arr) totsum+=it;
            if(totsum - d <0 || (totsum-d)%2) return false;
            return perfectSum(arr,(totsum-d)/2);
        }
        int findTargetSumWays(vector<int>& nums, int target) {
            return countPartitions(nums,target);
        }
    };
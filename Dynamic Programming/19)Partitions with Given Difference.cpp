Partitions with Given Difference
Given an array arr[], partition it into two subsets(possibly empty) such that each element must belong to only one subset. Let the sum of the elements of these two subsets be sum1 and sum2. Given a difference d, count the number of partitions in which sum1 is greater than or equal to sum2 and the difference between sum1 and sum2 is equal to d. 

Examples :
Input: arr[] =  [5, 2, 6, 4], d = 3
Output: 1
Explanation: There is only one possible partition of this array. Partition : {6, 4}, {5, 2}. The subset difference between subset sum is: (6 + 4) - (5 + 2) = 3.

Input: arr[] = [1, 1, 1, 1], d = 0 
Output: 6 
Explanation: We can choose two 1's from indices {0,1}, {0,2}, {0,3}, {1,2}, {1,3}, {2,3} and put them in sum1 and remaning two 1's in sum2.
Thus there are total 6 ways for partition the array arr. 

Input: arr[] = [1, 2, 1, 0, 1, 3, 3], d = 11
Output: 2

1st Way:- MEMOIZATION
class Solution {
    public:
    int mod=(int)(1e9+7);
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
        return dp[ind][target]=(take+not_take)%mod;
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
  };

2nd Way:- TABULATION
class Solution {
    public:
    int mod=(int)(1e9+7);
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
                  dp[ind][sum]=(not_take+take)%mod;
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
  };

3rd Way:- SPACE OPTIMISATION
class Solution {
    public:
    int mod=(int)(1e9+7);
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
                  curr[sum]=(not_take+take)%mod;
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
  };
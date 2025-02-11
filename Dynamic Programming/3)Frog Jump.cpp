Frog Jump
Given an integer array height[] where height[i] represents the height of the i-th stair, a frog starts from the first stair and wants to reach the top. From any stair i, the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. The cost of a jump is the absolute difference in height between the two stairs. Determine the minimum total cost required for the frog to reach the top.

Example:
Input: heights[] = [20, 30, 40, 20] 
Output: 20
Explanation:  Minimum cost is incurred when the frog jumps from stair 0 to 1 then 1 to 3:
jump from stair 0 to 1: cost = |30 - 20| = 10
jump from stair 1 to 3: cost = |20-30|  = 10
Total Cost = 10 + 10 = 20

Input: heights[] = [30, 20, 50, 10, 40]
Output: 30
Explanation: Minimum cost will be incurred when frog jumps from stair 0 to 2 then 2 to 4:
jump from stair 0 to 2: cost = |50 - 30| = 20
jump from stair 2 to 4: cost = |40-50|  = 10
Total Cost = 20 + 10 = 30

1st Way:- MEMOIZATION
class Solution {
    public:
      int minCost(vector<int>& height) {
          // Code here
          int n=height.size();
          vector<int>dp(n+1,-1);
          return func(height,n-1,dp);
      }
      int func(vector<int>&height,int ind,vector<int>&dp){
          int n=height.size();
          if(ind == 0) return 0;
          if(dp[ind]!=-1) return dp[ind];
          int left = func(height,ind-1,dp)+abs(height[ind]-height[ind-1]);
          int right = INT_MAX;
          if(ind > 1) right =func(height,ind-2,dp)+abs(height[ind]-height[ind-2]);
          return dp[ind]=min(left,right);
      }
  };

2nd Way:- TABULATION
class Solution {
    public:
      int minCost(vector<int>& height) {
          // Code here
          int n=height.size();
          vector<int>dp(n+1,-1);
          dp[0]=0;
          for(int i=1;i<n;i++){
              int left = dp[i-1]+abs(height[i]-height[i-1]);
              int right =INT_MAX;
              if(i>1) right = dp[i-2]+abs(height[i]-height[i-2]);
              dp[i] = min(left,right);
          }
          return dp[n-1];
      }
  };

3rd Way:- SPACE OPTIMIZATION
class Solution {
    public:
      int minCost(vector<int>& height) {
          // Code here
          int n=height.size();
          int prev=0;
          int prev2=0;
          for(int i=1;i<n;i++){
              int left = prev+abs(height[i]-height[i-1]);
              int right = INT_MAX;
              if(i>1) right = prev2+abs(height[i]-height[i-2]);
              int curri=min(left,right);
              prev2=prev;
              prev=curri;
          }
          return prev;
      }
  };
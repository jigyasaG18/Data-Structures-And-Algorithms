Rod Cutting Problem
Given a rod of length n(size of price) inches and an array of prices, price. price[i] denotes the value of a piece of length i. Determine the maximum value obtainable by cutting up the rod and selling the pieces.

Example:
Input: price[] = [1, 5, 8, 9, 10, 17, 17, 20]
Output: 22
Explanation: The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5+17=22.

Input: price[] = [3, 5, 8, 9, 10, 17, 17, 20]
Output: 24
Explanation: The maximum obtainable value is 24 by cutting the rod into 8 pieces of length 1, i.e, 8*price[1]= 8*3 = 24.

Input: price[] = [1, 10, 3, 1, 3, 1, 5, 9]
Output: 40

1st Way:- MEMOIZATION
class Solution {
    public:
    int func(vector<int> &price,int ind,int rodlength,vector<vector<int>> &dp){
        int n=price.size();
        if(ind==0) return (rodlength*price[0]);
        if(dp[ind][rodlength]!=-1) return dp[ind][rodlength];
        int not_take=0+func(price,ind-1,rodlength,dp);
        int take=INT_MIN;
        int rod=ind+1;
        if(rod<=rodlength) take=price[ind]+func(price,ind,rodlength-rod,dp);
        return dp[ind][rodlength]=max(take,not_take);
    }
      int cutRod(vector<int> &price) {
          // code here
          int n=price.size();
          vector<vector<int>>dp(n,vector<int>(n+1,-1));
          return func(price,n-1,n,dp);
      }
  };

2nd Way:- TABULATION
class Solution {
    public:
      int cutRod(vector<int> &price) {
          // code here
          int n=price.size();
          vector<vector<int>>dp(n,vector<int>(n+1,0));
          for(int i=0;i<=n;i++) dp[0][i]=i*price[0];
          for(int ind=1;ind<n;ind++){
              for(int rod=0;rod<=n;rod++){
          int not_take=0+dp[ind-1][rod];
        int take=INT_MIN;
        int rodlength=ind+1;
        if(rodlength<=rod) take=price[ind]+dp[ind][rod-rodlength];
        dp[ind][rod]=max(take,not_take);
              }
          }
          return dp[n-1][n];
      }
  };

3rd Way:- SPACE OPTIMISATION
class Solution {
    public:
      int cutRod(vector<int> &price) {
          // code here
          int n=price.size();
          vector<int>prev(n+1,0);
          vector<int>curr(n+1,0);
          for(int i=0;i<=n;i++) prev[i]=i*price[0];
          for(int ind=1;ind<n;ind++){
              for(int rod=0;rod<=n;rod++){
          int not_take=0+prev[rod];
        int take=INT_MIN;
        int rodlength=ind+1;
        if(rodlength<=rod) take=price[ind]+curr[rod-rodlength];
        curr[rod]=max(take,not_take);
              }
              prev=curr;
          }
          return prev[n];
      }
  };
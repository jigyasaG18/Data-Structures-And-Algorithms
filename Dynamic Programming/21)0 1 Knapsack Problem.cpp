0 - 1 Knapsack Problem
Given n items, each with a specific weight and value, and a knapsack with a capacity of W, the task is to put the items in the knapsack such that the sum of weights of the items <= W and the sum of values associated with them is maximized. 
Note: You can either place an item entirely in the bag or leave it out entirely. Also, each item is available in single quantity.

Examples :
Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1] 
Output: 3
Explanation: Choose the last item, which weighs 1 unit and has a value of 3.

Input: W = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6] 
Output: 0
Explanation: Every item has a weight exceeding the knapsack's capacity (3).

Input: W = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 2, 3] 
Output: 80
Explanation: Choose the third item (value 30, weight 2) and the last item (value 50, weight 3) for a total value of 80.

1st Way:- MEMOIZATION
class Solution {
  public:
  int func(int ind,int W,vector<int> &val, vector<int> &wt,vector<vector<int>>& dp){
      if(ind==0){
          if(wt[ind]<=W) return val[0];
          else return 0;
      }
      if(dp[ind][W]!=-1) return dp[ind][W];
      int not_take=0+func(ind-1,W,val,wt,dp);
      int take=INT_MIN;
      if(wt[ind]<=W){
          take=val[ind]+func(ind-1,W-wt[ind],val,wt,dp);
      }
      return dp[ind][W]=max(take,not_take);
  }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
        return func(n-1,W,val,wt,dp);
    }
};

2nd Way:- TABULATION
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(W+1,0));
        for(int w=wt[0];w<=W;w++) dp[0][w]=val[0];
        for(int ind=1;ind<n;ind++){
            for(int w=0;w<=W;w++){
                int not_take=0+dp[ind-1][w];
                int take=INT_MIN;
                if(wt[ind]<=w){
                    take=val[ind]+dp[ind-1][w-wt[ind]];
                }
                dp[ind][w]=max(take,not_take);
            }
        }
        return dp[n-1][W];
    }
};

3rd Way:- SPACE OPTIMISATION
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<int>prev(W+1,0),curr(W+1,0);
        for(int w=wt[0];w<=W;w++) prev[w]=val[0];
        for(int ind=1;ind<n;ind++){
            for(int w=0;w<=W;w++){
                int not_take=0+prev[w];
                int take=INT_MIN;
                if(wt[ind]<=w){
                    take=val[ind]+prev[w-wt[ind]];
                }
                curr[w]=max(take,not_take);
            }
            prev=curr;
        }
        return prev[W];
    }
};
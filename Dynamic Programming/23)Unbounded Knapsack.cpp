Unbounded Knapsack
Given a set of items, each with a weight and a value, represented by the array wt and val respectively. Also, a knapsack with a weight limit capacity.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.

Examples:
Input: val = [1, 1], wt = [2, 1], capacity = 3
Output: 3
Explanation: The optimal choice is to pick the 2nd element 3 times.

Input: val[] = [6, 1, 7, 7], wt[] = [1, 3, 4, 5], capacity = 8
Output: 48
Explanation: The optimal choice is to pick the 1st element 8 times.

Input: val[] = [6, 8, 7, 100], wt[] = [2, 3, 4, 5], capacity = 1
Output: 0
Explanation: We can't pick any element .hence, total profit is 0.

1st Way:- MEMOIZATION
class Solution {
  public:
  int func(vector<int>& val, vector<int>& wt, int capacity,int ind,vector<vector<int>> &dp){
      if(ind==0) return ((capacity/wt[0])*val[0]);
      if(dp[ind][capacity]!=-1) return dp[ind][capacity];
      int not_take=0+func(val,wt,capacity,ind-1,dp);
      int take=INT_MIN;
      if(wt[ind]<=capacity) take=val[ind]+func(val,wt,capacity-wt[ind],ind,dp);
      return dp[ind][capacity]=max(take,not_take);
  }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
        return func(val,wt,capacity,n-1,dp);
    }
};

2nd Way:- TABULATION
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<vector<int>>dp(n,vector<int>(capacity+1,0));
        for(int i=0;i<=capacity;i++) dp[0][i]=((i/wt[0])*val[0]);
        for(int ind=1;ind<n;ind++){
            for(int i=0;i<=capacity;i++){
                int not_take=0+dp[ind-1][i];
                int take=INT_MIN;
                if(wt[ind]<=i) take=val[ind]+dp[ind][i-wt[ind]];
                dp[ind][i]=max(not_take,take);
            }
        }
        return dp[n-1][capacity];
    }
};

3rd Way:- SPACE OPTIMISATION
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        vector<int>prev(capacity+1,0);
        vector<int>curr(capacity+1,0);
        for(int i=0;i<=capacity;i++) prev[i]=((i/wt[0])*val[0]);
        for(int ind=1;ind<n;ind++){
            for(int i=0;i<=capacity;i++){
                int not_take=0+prev[i];
                int take=INT_MIN;
                if(wt[ind]<=i) take=val[ind]+curr[i-wt[ind]];
                curr[i]=max(not_take,take);
            }
            prev=curr;
        }
        return prev[capacity];
    }
};
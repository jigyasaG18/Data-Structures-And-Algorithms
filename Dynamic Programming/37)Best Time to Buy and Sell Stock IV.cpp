Best Time to Buy and Sell Stock IV
You are given an integer array prices where prices[i] is the price of a given stock on the ith day, and an integer k.
Find the maximum profit you can achieve. You may complete at most k transactions: i.e. you may buy at most k times and sell at most k times.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: k = 2, prices = [2,4,1]
Output: 2
Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.

Example 2:
Input: k = 2, prices = [3,2,6,5,0,3]
Output: 7
Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4. Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.

1st Way:- MEMOIZATION
class Solution {
    public:
    int func(int ind,int buy,int cap,vector<int>& prices,vector<vector<vector<int>>>&dp){
        int n=prices.size();
        if(cap==0) return 0;
        if(ind==n) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        if(buy==1){
         return dp[ind][buy][cap]=max(-prices[ind]+func(ind+1,0,cap,prices,dp),0+func(ind+1,1,cap,prices,dp));
        }
        else{
            return dp[ind][buy][cap]=max(prices[ind]+func(ind+1,1,cap-1,prices,dp),0+func(ind+1,0,cap,prices,dp));
        }
    }
        int maxProfit(int k, vector<int>& prices) {
            int n=prices.size();
            vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
            return func(0,1,k,prices,dp);
        }
    };

2nd Way:- TABULATION
class Solution {
    public:
        int maxProfit(int k, vector<int>& prices) {
             int n=prices.size();
            vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
            for(int ind=n-1;ind>=0;ind--){
                for(int buy=0;buy<=1;buy++){
                    for(int cap=1;cap<=k;cap++){
        if(buy==1){
         dp[ind][buy][cap]=max(-prices[ind]+dp[ind+1][0][cap],0+dp[ind+1][1][cap]);
        }
        else{
        dp[ind][buy][cap]=max(prices[ind]+dp[ind+1][1][cap-1],0+dp[ind+1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][k];
        }
    };

3rd Way:- SPACE OPTIMISATION
class Solution {
    public:
        int maxProfit(int k, vector<int>& prices) {
            int n=prices.size();
            vector<vector<int>>after(2,vector<int>(k+1,0));
            vector<vector<int>>curr(2,vector<int>(k+1,0));
            for(int ind=n-1;ind>=0;ind--){
                for(int buy=0;buy<=1;buy++){
                    for(int cap=1;cap<=k;cap++){
        if(buy==1){
         curr[buy][cap]=max(-prices[ind]+after[0][cap],0+after[1][cap]);
        }
        else{
        curr[buy][cap]=max(prices[ind]+after[1][cap-1],0+after[0][cap]);
                    }
                }
            }
            after=curr;
        }
        return after[1][k];
        }
    };
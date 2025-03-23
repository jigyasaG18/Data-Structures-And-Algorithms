Best Time to Buy and Sell Stock III
You are given an array prices where prices[i] is the price of a given stock on the ith day.
Find the maximum profit you can achieve. You may complete at most two transactions.
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

Example 1:
Input: prices = [3,3,5,0,0,3,1,4]
Output: 6
Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are engaging multiple transactions at the same time. You must sell before buying again.

Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transaction is done, i.e. max profit = 0.

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
        int maxProfit(vector<int>& prices) {
            int n=prices.size();
            vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
            return func(0,1,2,prices,dp);
        }
    };

2nd Way:- TABULATION
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n=prices.size();
            vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
            for(int ind=n-1;ind>=0;ind--){
                for(int buy=0;buy<=1;buy++){
                    for(int cap=1;cap<=2;cap++){
        if(buy==1){
         dp[ind][buy][cap]=max(-prices[ind]+dp[ind+1][0][cap],0+dp[ind+1][1][cap]);
        }
        else{
        dp[ind][buy][cap]=max(prices[ind]+dp[ind+1][1][cap-1],0+dp[ind+1][0][cap]);
                    }
                }
            }
        }
        return dp[0][1][2];
        }
    };

3rd Way:- SPACE OPTIMISATION
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n=prices.size();
            vector<vector<int>>after(2,vector<int>(3,0));
            vector<vector<int>>curr(2,vector<int>(3,0));
            for(int ind=n-1;ind>=0;ind--){
                for(int buy=0;buy<=1;buy++){
                    for(int cap=1;cap<=2;cap++){
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
        return after[1][2];
        }
    };
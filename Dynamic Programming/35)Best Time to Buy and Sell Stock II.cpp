Best Time to Buy and Sell Stock II
You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 7
Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
Total profit is 4 + 3 = 7.

Example 2:
Input: prices = [1,2,3,4,5]
Output: 4
Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
Total profit is 4.

Example 3:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.

1st Way:- MEMOIZATION
class Solution {
    public:
    class Solution {
        public:
        int func(int ind,int buy,vector<int>& prices,vector<vector<int>>& dp){
            int n=prices.size();
            int profit=0;
            if(ind==n) return 0;
            if(dp[ind][buy]!=-1) return dp[ind][buy];
            if(buy){
         profit=max((-prices[ind]+func(ind+1,0,prices,dp)),(0+func(ind+1,1,prices,dp)));
            }
            else{
            profit=max((prices[ind]+func(ind+1,1,prices,dp)),(0+func(ind+1,0,prices,dp)));
            }
            return dp[ind][buy]=profit;
        }
            int maxProfit(vector<int>& prices) {
                int n=prices.size();
                long long int profit=0;
                vector<vector<int>>dp(n,vector<int>(2,-1));
                return func(0,1,prices,dp);
            }
        };

2nd Way:- TABULATION
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n=prices.size();
            int profit=0;
            vector<vector<int>>dp(n+1,vector<int>(2,0));
            dp[n][0]=0;
            dp[n][1]=0;
            for(int ind=n-1;ind>=0;ind--){
                for(int buy=0;buy<=1;buy++){
                    if(buy){
    profit=max(-prices[ind]+dp[ind+1][0],0+dp[ind+1][1]);
                    }
                    else{
    profit=max(prices[ind]+dp[ind+1][1],0+dp[ind+1][0]);
                    }
                    dp[ind][buy]=profit;
                }
            }
            return dp[0][1];
        }
    };

3rd Way:- SPACE OPTIMISATION
class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int n=prices.size();
            int profit=0;
            vector<int>ahead(2,0);
            vector<int>curr(2,0);
            ahead[0]=0;
            ahead[1]=0;
            for(int ind=n-1;ind>=0;ind--){
                for(int buy=0;buy<=1;buy++){
                    if(buy){
    profit=max(-prices[ind]+ahead[0],0+ahead[1]);
                    }
                    else{
    profit=max(prices[ind]+ahead[1],0+ahead[0]);
                    }
                    curr[buy]=profit;
                }
                ahead=curr;
            }
            return ahead[1];
        }
    };
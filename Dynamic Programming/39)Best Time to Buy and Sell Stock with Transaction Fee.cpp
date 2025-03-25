Best Time to Buy and Sell Stock with Transaction Fee
You are given an array prices where prices[i] is the price of a given stock on the ith day, and an integer fee representing a transaction fee.
Find the maximum profit you can achieve. You may complete as many transactions as you like, but you need to pay the transaction fee for each transaction.
Note:
You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
The transaction fee is only charged once for each stock purchase and sale.
 

Example 1:
Input: prices = [1,3,2,8,4,9], fee = 2
Output: 8
Explanation: The maximum profit can be achieved by:
- Buying at prices[0] = 1
- Selling at prices[3] = 8
- Buying at prices[4] = 4
- Selling at prices[5] = 9
The total profit is ((8 - 1) - 2) + ((9 - 4) - 2) = 8.

Example 2:
Input: prices = [1,3,7,5,10,3], fee = 3
Output: 6

1st Way:- MEMOIZATION
class Solution {
    public:
    int func(int ind,int buy,vector<int>& prices,vector<vector<int>>& dp,int fee){
        int n=prices.size();
        int profit=0;
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy){
     profit=max((-prices[ind]+func(ind+1,0,prices,dp,fee)),(0+func(ind+1,1,prices,dp,fee)));
        }
        else{
        profit=max((prices[ind]-fee+func(ind+1,1,prices,dp,fee)),(0+func(ind+1,0,prices,dp,fee)));
        }
        return dp[ind][buy]=profit;
    }
        int maxProfit(vector<int>& prices, int fee) {
            int n=prices.size();
            int profit=0;
            vector<vector<int>>dp(n,vector<int>(2,-1));
            return func(0,1,prices,dp,fee);
        }
    };

2nd Way:- TABULATION
class Solution {
    public:
        int maxProfit(vector<int>& prices, int fee) {
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
    profit=max(prices[ind]-fee+dp[ind+1][1],0+dp[ind+1][0]);
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
        int maxProfit(vector<int>& prices, int fee) {
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
    profit=max(prices[ind]-fee+ahead[1],0+ahead[0]);
                    }
                    curr[buy]=profit;
                }
                ahead=curr;
            }
            return ahead[1];
        }
    };
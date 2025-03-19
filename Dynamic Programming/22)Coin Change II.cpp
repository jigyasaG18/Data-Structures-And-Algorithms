Coin Change II
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
You may assume that you have an infinite number of each kind of coin.
The answer is guaranteed to fit into a signed 32-bit integer.

Example 1:
Input: amount = 5, coins = [1,2,5]
Output: 4
Explanation: there are four ways to make up the amount:
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

Example 2:
Input: amount = 3, coins = [2]
Output: 0
Explanation: the amount of 3 cannot be made up just with coins of 2.

Example 3:
Input: amount = 10, coins = [10]
Output: 1

1st Way:- MEMOIZATION
class Solution {
    public:
    int func(vector<int>& coins, int amount, int ind, vector<vector<int>> &dp){
        if(ind==0) return (amount % coins[0] == 0);
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int not_take = func(coins,amount,ind-1,dp);
        int take = 0;
        if(coins[ind]<=amount){
            take=func(coins,amount-coins[ind],ind,dp);
        }
        return dp[ind][amount]=take+not_take;
    }
        int change(int amount, vector<int>& coins) {
            int n=coins.size();
            vector<vector<int>>dp(n,vector<int>(amount+1,-1));
            return func(coins,amount,n-1,dp);
        }
    };

2nd Way:- TABULATION
class Solution {
    public:
        int change(int amount, vector<int>& coins) {
            int n=coins.size();
            vector<vector<int>>dp(n,vector<int>(amount+1,0));
            for(int tar=0;tar<=amount;tar++) dp[0][tar]=(tar % coins[0] == 0);
            for(int ind=1;ind<n;ind++){
                for(int tar=0;tar<=amount;tar++){
                    int not_take=dp[ind-1][tar];
                    int take=0;
                    if(coins[ind]<=tar){
                        take=dp[ind][tar-coins[ind]];
                    }
                    dp[ind][tar]=not_take+take;
                }
            }
            return dp[n-1][amount];
        }
    };

3rd Way:- SPACE OPTIMISATION
class Solution {
    public:
        int change(int amount, vector<int>& coins) {
            int n=coins.size();
            vector<int>curr(amount+1,0);
            vector<int>prev(amount+1,0);
            for(int tar=0;tar<=amount;tar++) prev[tar]=(tar % coins[0] == 0);
            for(int ind=1;ind<n;ind++){
                for(int tar=0;tar<=amount;tar++){
                    long long int not_take=prev[tar];
                    long long int take=0;
                    if(coins[ind]<=tar){
                        take=curr[tar-coins[ind]];
                    }
                    curr[tar]=not_take+take;
                }
                prev=curr;
            }
            return prev[amount];
        }
    };
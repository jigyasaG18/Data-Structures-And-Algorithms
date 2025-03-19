Minimum Coins
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.

Example 1: Input: coins = [1,2,5], amount = 11
Output: 3
Explanation: 11 = 5 + 5 + 1

Example 2: Input: coins = [2], amount = 3
Output: -1
Example 3:

Input: coins = [1], amount = 0
Output: 0

1st Way:- MEMOIZATION
class Solution {
    public:
    int func(vector<int>& coins, int amount, int ind,vector<vector<int>> &dp){
        int n=coins.size();
        if(ind==0){
            if(amount % coins[0]==0) return amount/coins[0];
            else return 1e9;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int not_take= 0+func(coins,amount,ind-1,dp);
        int take=INT_MAX;
        if(coins[ind]<=amount) take=1+func(coins,amount-coins[ind],ind,dp);
        return dp[ind][amount]=min(not_take,take);
    }
        int coinChange(vector<int>& coins, int amount) {
            int n=coins.size();
            vector<vector<int>>dp(n,vector<int>(amount+1,-1));
            int ans= func(coins,amount,n-1,dp);
            if(ans >= 1e9) return -1;
            else return ans;
        }
    };

2nd Way:- TABULATION
class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            int n=coins.size();
            vector<vector<int>>dp(n,vector<int>(amount+1,0));
            for(int tar=0;tar<=amount;tar++){
                if(tar % coins[0]==0) dp[0][tar]=tar/coins[0];
                else dp[0][tar]=1e9;
            }
            for(int ind=1;ind<n;ind++){
                for(int tar=0;tar<=amount;tar++){
                    int not_take=0+dp[ind-1][tar];
                    int take=INT_MAX;
                    if(coins[ind]<=tar) take=1+dp[ind][tar-coins[ind]];
                    dp[ind][tar]=min(take,not_take);
                }
            }
            int ans= dp[n-1][amount];
            if(ans >= 1e9) return -1;
            else return ans;
        }
    };

3rd Way:- SPACE OPTIMISATION
class Solution {
    public:
        int coinChange(vector<int>& coins, int amount) {
            int n=coins.size();
            vector<int>prev(amount+1,0);
            vector<int>curr(amount+1,0);
            for(int tar=0;tar<=amount;tar++){
                if(tar % coins[0]==0) prev[tar]=tar/coins[0];
                else prev[tar]=1e9;
            }
            for(int ind=1;ind<n;ind++){
                for(int tar=0;tar<=amount;tar++){
                    int not_take=0+prev[tar];
                    int take=INT_MAX;
                    if(coins[ind]<=tar) take=1+curr[tar-coins[ind]];
                    curr[tar]=min(take,not_take);
                }
                prev=curr;
            }
            int ans= prev[amount];
            if(ans >= 1e9) return -1;
            else return ans;
        }
    };
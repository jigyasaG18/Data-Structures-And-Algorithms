House Robber or Maximum sum of non-adjacent elements
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

Example 1:
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

1st Way:- MEMOIZATION
class Solution {
    public:
        int rob(vector<int>& nums) {
            int n=nums.size();
            vector<int>dp(n+1,-1);
            return f(n-1,nums,dp);
        }
        int f(int ind,vector<int>&nums,vector<int>&dp){
            if(ind==0) return nums[ind];
            if(ind<0) return 0;
            if(dp[ind]!=-1) return dp[ind];
            int pick=nums[ind]+f(ind-2,nums,dp);
            int not_pick=0+f(ind-1,nums,dp);
            return dp[ind]=max(pick,not_pick);
        }
    };

2nd Way:- TABULATION
class Solution {
    public:
        int rob(vector<int>& nums) {
            int n=nums.size();
            vector<int>dp(n+1,-1);
            dp[0]=nums[0];
            for(int i=1;i<n;i++){
                int pick=nums[i];
                if(i>1) pick+=dp[i-2];
                int not_pick=dp[i-1];
                dp[i]=max(pick,not_pick);
            }
            return dp[n-1];
        }
    };

3rd Way:- SPACE OPTIMIZATION
class Solution {
    public:
        int rob(vector<int>& nums) {
            int n=nums.size();
          int prev=nums[0];
          int prev2=0;
          for(int i=0;i<n;i++){
            int pick=nums[i];
            if(i>1) pick += prev2;
            int not_pick = 0+prev;
            int curri = max(pick,not_pick);
            prev2=prev;
            prev=curri;
          }
          return prev;
        }
    };
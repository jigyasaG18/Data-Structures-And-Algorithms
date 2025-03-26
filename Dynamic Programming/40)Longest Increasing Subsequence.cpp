Longest Increasing Subsequence
Given an integer array nums, return the length of the longest strictly increasing subsequence.

Example 1:
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.

Example 2:
Input: nums = [0,1,0,3,2,3]
Output: 4

Example 3:
Input: nums = [7,7,7,7,7,7,7]
Output: 1

1st Way:- MEMOIZATION
class Solution {
    public:
    int func(int ind,int prev_ind,vector<int>& nums,vector<vector<int>>& dp){
        int n=nums.size();
        if(ind==n) return 0;
        if(dp[ind][prev_ind+1]!=-1) return dp[ind][prev_ind+1];
        int len=0+func(ind+1,prev_ind,nums,dp);
        if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
            len=max(len,1+func(ind+1,ind,nums,dp));
        }
        return dp[ind][prev_ind+1]=len;
    }
        int lengthOfLIS(vector<int>& nums) {
            int n=nums.size();
            vector<vector<int>>dp(n,vector<int>(n+1,-1));
            return func(0,-1,nums,dp);
        }
    };

2nd Way:- TABULATION
class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            int n=nums.size();
            vector<vector<int>>dp(n+1,vector<int>(n+1,0));
            for(int ind=n-1;ind>=0;ind--){
                for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
                    int len=0+dp[ind+1][prev_ind+1];
                    if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
                        len=max(len,1+dp[ind+1][ind+1]);
                    }
                    dp[ind][prev_ind+1]=len;
                }
            }
            return dp[0][-1+1];
        }
    };

3rd Way:- SPACE OPTIMISATION
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int prev_ind=ind-1;prev_ind>=-1;prev_ind--){
                int len=0+next[prev_ind+1];
                if(prev_ind==-1 || nums[ind]>nums[prev_ind]){
                    len=max(len,1+next[ind+1]);
                }
                curr[prev_ind+1]=len;
            }
            next=curr;
        }
        return next[-1+1];
    }
};

4th Way:-
class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            int n=nums.size();
            vector<int>dp(n,1);
            int maxi=0;
            for(int i=0;i<n;i++){
                for(int prev=0;prev<i;prev++){
                    if(nums[prev]<nums[i]){
                        dp[i]=max(dp[i],1+dp[prev]);
                    }
                }
                maxi=max(maxi,dp[i]);
            }
            return maxi;
        }
    };
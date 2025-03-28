Subsets II
Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

class Solution {
    public:
    void subsets(int ind, vector<int> &nums,vector<int> &ans, vector<vector<int>> &res){
        int n=nums.size();
        res.push_back(ans);
        for(int i=ind;i<n;i++){
            if(i>ind && nums[i]==nums[i-1]) continue;
            ans.push_back(nums[i]);
            subsets(i+1,nums,ans,res);
            ans.pop_back();
        }
    }
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            vector<vector<int>>res;
            vector<int>ans;
            sort(nums.begin(),nums.end());
            subsets(0,nums,ans,res);
            return res;
        }
    };
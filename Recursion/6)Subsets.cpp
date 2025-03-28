Subsets
Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]

class Solution {
    public:
    void func(int i,vector<int>& nums,vector<int>& res,vector<vector<int>> &ans){
        int n=nums.size();
        if(i==n){
            ans.push_back(res);
            return;
        }
        res.push_back(nums[i]);
        func(i+1,nums,res,ans);
        res.pop_back();
        func(i+1,nums,res,ans);
    }
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<vector<int>>ans;
            vector<int>res;
            func(0,nums,res,ans);
            return ans;
        }
    };
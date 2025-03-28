Permutations
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]

1st Way:- RECURSIVE
class Solution {
    public:
    void func(vector<int> &ans,vector<int>& nums,vector<vector<int>> &res,int freq[]){
        int n=nums.size();
        if(ans.size()==n){
            res.push_back(ans);
            return;
        }
        for(int i=0;i<n;i++){
            if(!freq[i]){
            ans.push_back(nums[i]);
            freq[i]=1;
            func(ans,nums,res,freq);
            freq[i]=0;
            ans.pop_back();
            }
        }
    }
        vector<vector<int>> permute(vector<int>& nums) {
            int n=nums.size();
            vector<vector<int>>res;
            vector<int>ans;
            int freq[n];
            for(int i=0;i<n;i++) freq[i]=0;
            func(ans,nums,res,freq);
            return res;
        }
    };

2nd Way:- BACKTRACKING
class Solution {
    public:
    void func(int ind,vector<int>&nums,vector<vector<int>>&res){
        int n=nums.size();
        if(ind==n){
            res.push_back(nums);
            return;
        }
        for(int i=ind;i<n;i++){
            swap(nums[ind],nums[i]);
            func(ind+1,nums,res);
            swap(nums[ind],nums[i]);
        }
    }
        vector<vector<int>> permute(vector<int>& nums) {
            vector<vector<int>>res;
            vector<int>ans;
            func(0,nums,res);
            return res;
        }
    };
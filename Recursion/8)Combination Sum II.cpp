Combination Sum II
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]

class Solution {
    public:
    void find(int ind,int target,vector<int> &arr,vector<int> &ans,vector<vector<int>> &res){
        int n=arr.size();
        if(target==0){
            res.push_back(ans);
            return;
        }
        for(int i=ind;i<n;i++){
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i]>target) break;
            ans.push_back(arr[i]);
            find(i+1,target-arr[i],arr,ans,res);
            ans.pop_back();
        }
    }
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            sort(candidates.begin(),candidates.end());
            vector<vector<int>>res;
            vector<int>ans;
            find(0,target,candidates,ans,res);
            return res;
        }
    };
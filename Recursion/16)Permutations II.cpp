Permutations II
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

Example 1:
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]

Example 2:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

class Solution {
    public:
        void func(int ind, vector<int>& nums, vector<vector<int>>& res) {
            int n = nums.size();
            if (ind == n) {
                res.push_back(nums); // Add valid permutation
                return;
            }
    unordered_set<int> used;  // Set to track used elements at the current recursion level
            for (int i = ind; i < n; i++) {
                // Only proceed if nums[i] has not been used in this level of recursion
                if (used.find(nums[i]) != used.end()) {
                    continue; // Skip duplicates
                }
                used.insert(nums[i]); // Mark this element as used
                swap(nums[ind], nums[i]); // Make the swap
                func(ind + 1, nums, res); // Recur to fill the next position
                swap(nums[ind], nums[i]); // Backtrack to restore original state
            }
        }
        
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            sort(nums.begin(), nums.end()); // Sort to handle duplicates
            vector<vector<int>> res; // Result vector
            func(0, nums, res); // Generate permutations
            return res; // Return the results
        }
    };
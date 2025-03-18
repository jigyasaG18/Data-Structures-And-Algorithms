Partition to K Equal Sum Subsets
Given an integer array nums and an integer k, return true if it is possible to divide this array into k non-empty subsets whose sums are all equal.

Example 1:
Input: nums = [4,3,2,3,5,2,1], k = 4
Output: true
Explanation: It is possible to divide it into 4 subsets (5), (1, 4), (2,3), (2,3) with equal sums.

Example 2:
Input: nums = [1,2,3,4], k = 3
Output: false

class Solution {
    public:
        bool solver(vector<int>& nums, vector<int>& visited, int start_index, int k,
                    int current_sum, int target) {
            if (k == 0) return true;
            if (current_sum == target) {
    
                return solver(nums, visited, 0, k - 1, 0, target);
            }
    
            for (int i = start_index; i < nums.size(); i++) {
                if (!visited[i] && current_sum + nums[i] <= target) {
                    visited[i] = 1;
                    if (solver(nums, visited, i + 1, k, current_sum + nums[i],
                               target)) {
                        return true;
                    }
                    visited[i] = 0;
                    if (current_sum == 0)
                        return true;
                }
            }
            return false;
        }
        bool canPartitionKSubsets(vector<int>& nums, int k) {
            int sum = accumulate(nums.begin(), nums.end(), 0);
            if (sum % k != 0) return false;
            int target = sum / k;
            vector<int> visited(nums.size(), false);
            sort(nums.begin(), nums.end());
            return solver(nums, visited, 0, k, 0, target);
        }
    };
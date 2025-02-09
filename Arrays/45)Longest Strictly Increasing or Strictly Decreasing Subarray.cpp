Longest Strictly Increasing or Strictly Decreasing Subarray
You are given an array of integers nums. Return the length of the longest subarray of nums which is either strictly increasing or strictly decreasing
.
Example 1:
Input: nums = [1,4,3,3,2]
Output: 2
Explanation:
The strictly increasing subarrays of nums are [1], [2], [3], [3], [4], and [1,4].
The strictly decreasing subarrays of nums are [1], [2], [3], [3], [4], [3,2], and [4,3].
Hence, we return 2.

Example 2:
Input: nums = [3,3,3,3]
Output: 1
Explanation:
The strictly increasing subarrays of nums are [3], [3], [3], and [3].
The strictly decreasing subarrays of nums are [3], [3], [3], and [3].
Hence, we return 1.

Example 3:
Input: nums = [3,2,1]
Output: 3
Explanation:
The strictly increasing subarrays of nums are [3], [2], and [1].
The strictly decreasing subarrays of nums are [3], [2], [1], [3,2], [2,1], and [3,2,1].
Hence, we return 3.

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
         int n = nums.size();
        if (n == 0) return 0; // handle edge case of empty array
        
        int max_length = 1; // Maximum length is 1
        int increase = 1; 
        int decrease = 1;

        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                increase++ ; // increasing
                decrease = 1; //reset decrease counter
            } else if (nums[i] < nums[i - 1]) {
                decrease++ ; // decreasing
                increase = 1; //reset increase counter
            } else {
                // reset, since nums[i] == nums[i-1]
                increase= 1; 
                decrease = 1;
        }
         max_length = max(max(increase,decrease),max_length); // keep track of the maximum length
         }
        return max_length;
        }
    
}; 
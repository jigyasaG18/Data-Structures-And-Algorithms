Longest Increasing Subsequence using Binary Search
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

class Solution {
    public:
        int lengthOfLIS(vector<int>& nums) {
            int n=nums.size();
            vector<int>temp;
            temp.push_back(nums[0]);
            int len=1;
            for(int i=1;i<n;i++){
                if(nums[i]>temp.back()){
                    temp.push_back(nums[i]);
                    len++;
                }
                else{
                 auto it = lower_bound(temp.begin(), temp.end(), nums[i]);
                    *it = nums[i]; // Replace that position with nums[i]
                }
            }
            return len;
        }
    };
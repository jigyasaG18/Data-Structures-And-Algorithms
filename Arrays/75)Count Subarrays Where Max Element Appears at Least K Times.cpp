Count Subarrays Where Max Element Appears at Least K Times
You are given an integer array nums and a positive integer k.
Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.
A subarray is a contiguous sequence of elements within an array.

Example 1:
Input: nums = [1,3,2,3,3], k = 2
Output: 6
Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].

Example 2:
Input: nums = [1,4,2,1], k = 3
Output: 0
Explanation: No subarray contains the element 4 at least 3 times.

class Solution {
    public:
        long long countSubarrays(vector<int>& nums, int k) {
            int n=nums.size();
            int maxi=INT_MIN;
            long long cnt=0;
            int cntmaxi=0;
            int left=0;
            for(auto it : nums){
                maxi = max(maxi,it);
            }
            for(int right=0;right<n;right++){
                if(nums[right]==maxi) cntmaxi++;
                while(cntmaxi >= k){
                    if(nums[left]==maxi) cntmaxi--;
                    left++;
                }
                cnt += left;
            }
            return cnt;
        }
    };
Maximum Absolute Sum of Any Subarray
You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).
Return the maximum absolute sum of any (possibly empty) subarray of nums.
Note that abs(x) is defined as follows:
If x is a negative integer, then abs(x) = -x.
If x is a non-negative integer, then abs(x) = x.
 
Example 1:
Input: nums = [1,-3,2,3,-4]
Output: 5
Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.

Example 2:
Input: nums = [2,-5,1,-4,3,-2]
Output: 8
Explanation: The subarray [-5,1,-4] has absolute sum = abs(-5+1-4) = abs(-8) = 8.

class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int n=nums.size();
            long long int minsum = 0;
            long long int maxsum = 0;
            long long int maxi = INT_MIN; // to capture max sequence sum
            long long int mini = INT_MAX; // to capture min sequence sum
    
      // Calculate minimum subarray sum (Kadanes' algorithm for min sum)
            int i=0;
            while(i<n){
                minsum+=nums[i];
                mini=min(minsum,mini);
                if(minsum>0) minsum=0;
                i++;
            }
      // Calculate maximum subarray sum (Kadanes' algorithm for max sum)
            i=0;
            while(i<n){
                maxsum+=nums[i];
                maxi=max(maxsum,maxi);
                if(maxsum<0) maxsum=0;
                i++;
            }
            return max(abs(maxi),abs(mini));
        }
    };
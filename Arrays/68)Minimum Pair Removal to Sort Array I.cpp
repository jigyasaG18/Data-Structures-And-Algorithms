Minimum Pair Removal to Sort Array I
Given an array nums, you can perform the following operation any number of times:
Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
Replace the pair with their sum.
Return the minimum number of operations needed to make the array non-decreasing.
An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).

Example 1:
Input: nums = [5,2,3,1]
Output: 2
Explanation:
The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
The array nums became non-decreasing in two operations.

Example 2:
Input: nums = [1,2,2]
Output: 0
Explanation: The array nums is already sorted.

class Solution {
    public:
    bool issorted(vector<int>&nums){
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]>nums[i+1]) return false;
        }
        return true;
    }
        int minimumPairRemoval(vector<int>& nums) {
            int ans=0;
            while(!issorted(nums) && nums.size()>1){
                int minsum=1e9;
                int pos= -1;
                for(int i=0;i<nums.size()-1;i++){
                    int currsum=nums[i]+nums[i+1];
                    if(currsum<minsum){
                        minsum=currsum;
                        pos=i;
                    }
                }
                nums[pos]=nums[pos]+nums[pos+1];
                nums.erase(nums.begin()+pos+1);
                ans++;
            }
            return ans;
        }
    };
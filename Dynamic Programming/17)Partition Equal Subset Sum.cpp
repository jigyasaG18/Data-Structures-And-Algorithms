Partition Equal Subset Sum
Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.

Example 1:
Input: nums = [1,5,11,5]
Output: true
Explanation: The array can be partitioned as [1, 5, 5] and [11].

Example 2:
Input: nums = [1,2,3,5]
Output: false
Explanation: The array cannot be partitioned into equal sum subsets.

class Solution {
    public:
    bool isSubsetSum(vector<int>& arr, int sum) {
            // code here
            int n=arr.size();
            vector<bool>prev(sum+1,0),curr(sum+1,0);
            prev[0]=curr[0]=true;
            if(arr[0]<=sum) prev[arr[0]]=true;
            for(int ind=1;ind<n;ind++){
                for(int target=1;target<=sum;target++){
                    bool not_take=prev[target];
                    bool take=false;
                    if(arr[ind]<=target) take=prev[target-arr[ind]];
                    curr[target]=take||not_take;
                }
                prev=curr;
            }
            return prev[sum];
        }
        
        bool canPartition(vector<int>& nums) {
            int n=nums.size();
            int totalsum=0;
            for(int i=0;i<n;i++){
                totalsum += nums[i];
            }
            if(totalsum % 2 !=0) return false;
            int target = totalsum/2;
            if(isSubsetSum(nums,target)){
                return true;
            }
            return false;
        }
    };
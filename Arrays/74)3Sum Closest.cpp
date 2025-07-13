3Sum Closest
Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

class Solution {
    public:
        int threeSumClosest(vector<int>& nums, int target) {
            int n=nums.size();
            sort(nums.begin(),nums.end());
            int closest=nums[0]+nums[1]+nums[2];
            for(int i=0; i<n-2; i++){
                if(i!=0 && nums[i]==nums[i-1]){
                    continue;
                }
                int j=i+1;
                int k=n-1;
                while(j<k){
                    int sum=nums[i]+nums[j]+nums[k];
                    if(abs(sum-target) < abs(closest-target)){
                        closest=sum;
                    }
                    if(sum < target) j++;
                    else if(sum > target) k--;
                    else return sum;
                }
            }
            return closest;
        }
    };

Alternate Way or Modification in Question:-
Given an array arr[] and an integer target, the task is to find the sum of three integers in arr[] such that the sum is closest to target. 
Note: If multiple sums are closest to target, return the maximum one.

Examples:
Input: arr[] = [-1, 2, 2, 4], target = 4
Output: 5
Explanation: All possible triplets
[-1, 2, 2], sum = (-1) + 2 + 2 = 3
[-1, 2, 4], sum = (-1) + 2 + 4 = 5
[-1, 2, 4], sum = (-1) + 2 + 4 = 5
[2, 2, 4], sum = 2 + 2 + 4 = 8
Triplet [-1, 2, 2], [-1, 2, 4] and [-1, 2, 4] have sum closest to target, so return the maximum one, that is 5.

Input: arr[] = [1, 10, 4, 5], target = 10
Output: 10
Explanation: All possible triplets
[1, 10, 4], sum = (1 + 10 + 4) = 15
[1, 10, 5], sum = (1 + 10 + 5) = 16
[1, 4, 5], sum = (1 + 4 + 5) = 10
[10, 4, 5], sum = (10 + 4 + 5) = 19 
Triplet [1, 4, 5] has sum = 10 which is closest to target.

lass Solution {
    public:
      int closest3Sum(vector<int> &arr, int target) {
          // code here
          int n=arr.size();
          sort(arr.begin(),arr.end());
          int closest=arr[0]+arr[1]+arr[2];
          for(int i=0; i<n-2; i++){
              if(i!=0 && arr[i]==arr[i-1]){
                  continue;
              }
              int j=i+1;
              int k=n-1;
              while(j<k){
                  int sum=arr[i]+arr[j]+arr[k];
            // Update closest if we find a closer sum
              if (abs(sum - target) < abs(closest - target) || 
                  (abs(sum - target) == abs(closest - target) && sum > closest)) {
                  closest = sum;
              }
                  if(sum < target) j++;
                  else if(sum > target) k--;
                  else return sum;
              }
          }
          return closest;
      }
  };
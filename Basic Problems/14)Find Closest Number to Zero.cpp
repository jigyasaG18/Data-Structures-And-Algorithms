Find Closest Number to Zero
Given an integer array nums of size n, return the number with the value closest to 0 in nums. If there are multiple answers, return the number with the largest value.

Example 1:
Input: nums = [-4,-2,1,4,8]
Output: 1
Explanation:
The distance from -4 to 0 is |-4| = 4.
The distance from -2 to 0 is |-2| = 2.
The distance from 1 to 0 is |1| = 1.
The distance from 4 to 0 is |4| = 4.
The distance from 8 to 0 is |8| = 8.
Thus, the closest number to 0 in the array is 1.

Example 2:
Input: nums = [2,-1,1]
Output: 1
Explanation: 1 and -1 are both the closest numbers to 0, so 1 being larger is returned.

1st Way:-
class Solution {
    public:
        int findClosestNumber(vector<int>& nums) {
            int closest = nums[0];
            for (int i = 0; i < nums.size(); i++) {
                
                if (abs(nums[i]) < abs(closest) ||
                    (abs(nums[i]) == abs(closest) && nums[i] > closest))
                    closest = nums[i];
            }
            return closest;
        }
    };

2nd Way:- 
class Solution {
    public:
        int findClosestNumber(vector<int>& nums) {
            int closest=INT_MAX;
            sort(nums.begin(),nums.end());
            for(auto n:nums){
                if(abs(n-0)<=abs(closest)){
                    closest = n;
                }
            }
            return closest;
        }
    };
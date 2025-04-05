Minimum Difference Between Largest and Smallest Value in Three Moves
You are given an integer array nums.
In one move, you can choose one element of nums and change it to any value.
Return the minimum difference between the largest and smallest value of nums after performing at most three moves.

Example 1:
Input: nums = [5,3,2,4]
Output: 0
Explanation: We can make at most 3 moves.
In the first move, change 2 to 3. nums becomes [5,3,3,4].
In the second move, change 4 to 3. nums becomes [5,3,3,3].
In the third move, change 5 to 3. nums becomes [3,3,3,3].
After performing 3 moves, the difference between the minimum and maximum is 3 - 3 = 0.

Example 2:
Input: nums = [1,5,0,10,14]
Output: 1
Explanation: We can make at most 3 moves.
In the first move, change 5 to 0. nums becomes [1,0,0,10,14].
In the second move, change 10 to 0. nums becomes [1,0,0,0,14].
In the third move, change 14 to 1. nums becomes [1,0,0,0,1].
After performing 3 moves, the difference between the minimum and maximum is 1 - 0 = 1.
It can be shown that there is no way to make the difference 0 in 3 moves.

Example 3:
Input: nums = [3,100,20]
Output: 0
Explanation: We can make at most 3 moves.
In the first move, change 100 to 7. nums becomes [3,7,20].
In the second move, change 20 to 7. nums becomes [3,7,7].
In the third move, change 3 to 7. nums becomes [7,7,7].
After performing 3 moves, the difference between the minimum and maximum is 7 - 7 = 0.

class Solution {
    public:
        int minDifference(vector<int>& nums) {
            int n=nums.size();
            if(n<=4) return 0; //if we have 4 elements then also we can change the 3 elements to the last element and hence all elements same and diff=0
            sort(nums.begin(),nums.end());
            int mini=INT_MAX;
            for(int i=0;i<4;i++){
                mini=min(mini,nums[n-4+i]-nums[i]); //we have to change either first 3 elements or last 3 elements
            }
            return mini;
        }
    }; 
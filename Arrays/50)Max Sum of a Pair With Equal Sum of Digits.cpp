Max Sum of a Pair With Equal Sum of Digits
You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].
Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.

Example 1:
Input: nums = [18,43,36,13,7]
Output: 54
Explanation: The pairs (i, j) that satisfy the conditions are:
- (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
- (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
So the maximum sum that we can obtain is 54.

Example 2:
Input: nums = [10,12,19,14]
Output: -1
Explanation: There are no two numbers that satisfy the conditions, so we return -1.

class Solution {
    public:
        int maximumSum(vector<int>& nums) {
        unordered_map<int, int> digitSumMap; // Store max value for each digit sum
            int maxSum = -1; // Result for the maximum sum of pairs
    
            for(int num : nums) {
                int sumDigits = 0;
                int temp = num;
    
                // Calculate the sum of digits
                while(temp > 0) {
                    sumDigits += temp % 10;
                    temp /= 10;
                }
    // If the sum of digits is already in the map, we can calculate a potential max sum
                if(digitSumMap.count(sumDigits)) {
                    int currentMax = digitSumMap[sumDigits];
                    maxSum = max(maxSum, currentMax + num); 
                    // Update maxSum if this pair is larger
                    // Update the map with the max value for this digit sum
                    digitSumMap[sumDigits] = max(currentMax, num);
                } else {
                    // If it's not in the map, we just add it
                    digitSumMap[sumDigits] = num;
                }
            }
    
            return maxSum;
        }
    };
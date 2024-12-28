Count pairs with given sum
Given an array arr[] and an integer target. You have to find numbers of pairs in array arr[] which sums up to given target.

Examples:
Input: arr[] = [1, 5, 7, -1, 5], target = 6 
Output: 3
Explanation: Pairs with sum 6 are (1, 5), (7, -1) and (1, 5). 

Input: arr[] = [1, 1, 1, 1], target = 2 
Output: 6
Explanation: Pairs with sum 2 are (1, 1), (1, 1), (1, 1), (1, 1), (1, 1), (1, 1).

Input: arr[] = [10, 12, 10, 15, -1], target = 125
Output: 0

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
        unordered_map<int, int> frequency;
        int count = 0;

        // Count frequencies of each element
        for (int num : arr) {
            frequency[num]++;
        }

        // Iterate and count pairs
        for (int num : arr) {
            int complement = target - num;

            // Check if the complement exists in the map
            if (frequency.find(complement) != frequency.end()) {
                count += frequency[complement];

                // If num and complement are the same, we need to discount the self-pair
                if (complement == num) {
                    count--;
                }
            }
        }

        // Each pair is counted twice (once for each order), so divide by 2
        return count / 2;
        
//Count Pairs:
//arr = [1, 2, 3, 4, 5]; 
//target = 5;
//frequency = 1:1,2: 1,3: 1,4: 1,5: 1 
//For num = 1, complement = 4 (found: count += 1)
//For num = 2, complement = 3 (found: count += 1)
//For num = 3, complement = 2 (here, we have already counted this in the previous step)
//For num = 4, complement = 1 (here, we have already counted this)
//For num = 5, complement = 0 (not found)
//Final Count:
//Without adjustments: count = 2
//Final step: return count / 2; gives 1.
    }
};


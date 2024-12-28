Two Sum - Pair with Given Sum
Given an array arr[] of positive integers and another integer target. Determine if there exists two distinct indices such that the sum of there elements is equals to target.

Examples:

Input: arr[] = [1, 4, 45, 6, 10, 8], target = 16
Output: true
Explanation: arr[3] + arr[4] = 6 + 10 = 16.

Input: arr[] = [1, 2, 4, 3, 6], target = 11
Output: false
Explanation: None of the pair makes a sum of 11.

Input: arr[] = [11], target = 11
Output: false
Explanation: No pair is possible as only one element is present in arr[].

1st Way:-
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        sort(arr.begin(), arr.end()); // Sort the array
        int left = 0, right = n - 1;
       
        
        // Use two pointers to find pairs
        while (left < right) {
            int sum = arr[left] + arr[right];
            if (sum == target) {
                return true;
                left++; // Move both pointers since we've found a pair
                right--;
            } 
            else if (sum < target) {
                left++; // Move the left pointer to increase the sum
            } 
            else {
                right--; // Move the right pointer to decrease the sum
            }
            
        }
        
      return false;   
    }
};

2nd Way:-
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
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
    }
};
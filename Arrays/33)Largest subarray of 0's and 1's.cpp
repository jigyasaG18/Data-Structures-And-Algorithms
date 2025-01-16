Largest subarray of 0's and 1's
Given an array arr of 0s and 1s. Find and return the length of the longest subarray with equal number of 0s and 1s.

Examples:
Input: arr[] = [1, 0, 1, 1, 1, 0, 0]
Output: 6
Explanation: arr[1...6] is the longest subarray with three 0s and three 1s.

Input: arr[] = [0, 0, 1, 1, 0]
Output: 4
Explnation: arr[0...3] or arr[1...4] is the longest subarray with two 0s and two 1s.

Input: arr[] = [0]
Output: 0
Explnation: There is no subarray with an equal number of 0s and 1s.

class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your code here
        int n = arr.size();
    map<int, int> map;
    map.insert({0, -1}); // Initialize with count 0 at index -1
    int maxlen = 0, count = 0;

    for (int i = 0; i < n; i++) {
        count += (arr[i] == 1) ? 1 : -1; // Increment count for 1's and decrement for 0's

        // Check if count already exists in the map
        if (map.find(count) != map.end()) {
            // Update maxlen if a longer subarray is found
            maxlen = max(maxlen, i - map[count]);
        } else {
            // If not found, store the first occurrence of this count
            map[count] = i; // map[count] always holds the first occurrence of count
        }
    }
    
    return maxlen; // Return the maximum length found
    }
};
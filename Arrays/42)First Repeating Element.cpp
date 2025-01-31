First Repeating Element
Given an array arr[], find the first repeating element. The element should occur more than once and the index of its first occurrence should be the smallest.
Note:- The position you return should be according to 1-based indexing. 

Examples:
Input: arr[] = [1, 5, 3, 4, 3, 5, 6]
Output: 2
Explanation: 5 appears twice and its first appearance is at index 2 which is less than 3 whose first the occurring index is 3.

Input: arr[] = [1, 2, 3, 4]
Output: -1
Explanation: All elements appear only once so answer is -1.

// User function template in C++

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(vector<int> &arr) {
        // code here
           int n = arr.size();
    unordered_map<int, int> mpp; // to store the first occurrence index of each element
    int mini = INT_MAX; // initialize to a value greater than any index

    for (int i = 0; i < n; i++) {
        // if the element is already seen
        if (mpp.find(arr[i]) != mpp.end()) {
// we found a repeated element, check if its first occurrence is the smallest
            mini = min(mini, mpp[arr[i]]);
        } else {
    // store the first occurrence index (1-based index)
            mpp[arr[i]] = i + 1; // store as 1-based index
        }
    }

    // If `mini` was updated, return it, otherwise return -1 indicating no repeating element
    return (mini == INT_MAX) ? -1 : mini;

    }
};
Minimum Jumps
Given an array arr[] of non-negative integers. Each array element represents the maximum length of the jumps that can be made forward from that element. This means if arr[i] = x, then we can jump any distance y such that y ≤ x. Find the minimum number of jumps to reach the end of the array starting from the first element. If an element is 0, then you cannot move through that element.

Note:  Return -1 if you can't reach the end of the array.

Examples : 

Input: arr[] = [1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9]
Output: 3 
Explanation: First jump from 1st element to 2nd element with value 3. From here we jump to 5th element with value 9, and from here we will jump to the last. 

Input: arr = [1, 4, 3, 2, 6, 7]
Output: 2 
Explanation: First we jump from the 1st to 2nd element and then jump to the last element.

Input: arr = [0, 10, 20]
Output: -1
Explanation: We cannot go anywhere from the 1st element.

Constraints:
2 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 105

// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        int n = arr.size();
    
    // Edge case: if the array has 0 or 1 elements
    if (n <= 1) {
        return 0;
    }
    
    // If the first element is 0, we cannot move anywhere
    if (arr[0] == 0) {
        return -1;
    }
    
    int jumps = 0; // Number of jumps made
    int currentEnd = 0; // The end of the range of the current jump
    int farthest = 0;   // The farthest index reachable with the next jump

    for (int i = 0; i < n - 1; i++) {
        // Update the farthest we can reach from current position
        farthest = max(farthest, i + arr[i]);

        // If we have reached the end of our current jump range
        if (i == currentEnd) {
            jumps++; // Increment the jump count
            currentEnd = farthest; // Update the end of the range for the next jump
            
            // If we can reach or pass the last index, we can return jumps
            if (currentEnd >= n - 1) {
                return jumps;
            }
        }

        int n = arr.size();
    
    // Edge case: if the array has 0 or 1 elements
    if (n <= 1) {
        return 0;
    }
    
    // If the first element is 0, we cannot move anywhere
    if (arr[0] == 0) {
        return -1;
    }
    
    int jumps = 0; // Number of jumps made
    int currentEnd = 0; // The end of the range of the current jump
    int farthest = 0;   // The farthest index reachable with the next jump

    for (int i = 0; i < n - 1; i++) {
        // Update the farthest we can reach from current position
        farthest = max(farthest, i + arr[i]);

        // If we have reached the end of our current jump range
        if (i == currentEnd) {
            jumps++; // Increment the jump count
            currentEnd = farthest; // Update the end of the range for the next jump
            
            // If we can reach or pass the last index, we can return jumps
            if (currentEnd >= n - 1) {
                return jumps;
            }
        }

        // If at any point the farthest point we can reach is not further than the current index,
        // it means we can't proceed further, hence we return -1
        if (farthest <= i) {
            return -1;
        }
    }

    return jumps; // Return the total number of jumps if we completed the loop
    }

    return jumps; // Return the total number of jumps if we completed the loop
    }
};

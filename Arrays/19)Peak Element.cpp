Peak Element
Given an array arr[] where no two adjacent elements are same, find the index of a peak element. An element is considered to be a peak if it is greater than its adjacent elements (if they exist). If there are multiple peak elements, return index of any one of them. The output will be "true" if the index returned by your function is correct; otherwise, it will be "false".
Note: Consider the element before the first element and the element after the last element to be negative infinity.

Examples :
Input: arr = [1, 2, 4, 5, 7, 8, 3]
Output: true
Explanation: arr[5] = 8 is a peak element because arr[4] < arr[5] > arr[6].

Input: arr = [10, 20, 15, 2, 23, 90, 80]
Output: true
Explanation: arr[1] = 20 and arr[5] = 90 are peak elements because arr[0] < arr[1] > arr[2] and arr[4] < arr[5] > arr[6]. 

Input: arr = [1, 2, 3]
Output: true
Explanation: arr[2] is a peak element because arr[1] < arr[2] and arr[2] is the last element, so it has negative infinity to its right.

class Solution {
  public:
    int peakElement(vector<int> &arr) {
        // Your code here
         int n = arr.size();
        // Handle edge cases where the array has only one element
        if (n == 1) return 0;

        // Check if the first element is a peak
        if (arr[0] > arr[1]) {
            return 0;
        }

        // Check for peaks in the middle of the array
        for (int i = 1; i < n - 1; i++) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                return i; // Return the index of the peak element
            }
        }

        // Check if the last element is a peak
        if (arr[n - 1] > arr[n - 2]) {
            return n - 1;
        }

        // If no peak is found
        return -1; 
    }
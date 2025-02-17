Palindrome Array
Given an array arr, the task is to find whether the arr is palindrome or not. If the arr is palindrome then return true else return false.
An array is said to be palindrome if its reverse array matches the original array. 

Examples:
Input: arr = [1, 2, 3, 2, 1]
Output: true
Explanation: Here we can see we have [1, 2, 3, 2, 1] if we reverse it we can find [1, 2, 3, 2, 1] which is the same as before. So, the answer is true.

Input: arr = [1, 2, 3, 4, 5]
Output: false
Explanation: Here we can see we have [1, 2, 3, 4, 5] if we reverse it we find [5, 4, 3, 2, 1] which is the not same as before. So, the answer false.

class Solution {
    public:
      bool isPerfect(vector<int> &arr) {
          // code here
      int n = arr.size();
      for (int i = 0; i < n ; i++) { // Iterate only up to end of array
          if (arr[i] != arr[n - 1]) { // Compare elements from the start and end
              return false;
          }
          n--;
      }
      return true; // If all comparisons pass, it's a palindrome
      }
  };
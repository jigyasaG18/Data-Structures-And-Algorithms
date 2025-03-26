Implement Quick Sort, a Divide and Conquer algorithm, to sort an array, arr[] in ascending order. Given an array, arr[], with starting index low and ending index high, complete the functions partition() and quickSort(). Use the last element as the pivot so that all elements less than or equal to the pivot come before it, and elements greater than the pivot follow it.
Note: The low and high are inclusive.

Examples:
Input: arr[] = [4, 1, 3, 9, 7]
Output: [1, 3, 4, 7, 9]
Explanation: After sorting, all elements are arranged in ascending order.

Input: arr[] = [2, 1, 6, 10, 4, 1, 3, 9, 7]
Output: [1, 1, 2, 3, 4, 6, 7, 9, 10]
Explanation: Duplicate elements (1) are retained in sorted order.

Input: arr[] = [5, 5, 5, 5]
Output: [5, 5, 5, 5]
Explanation: All elements are identical, so the array remains unchanged.

class Solution {
    public:
      // Function to sort an array using quick sort algorithm.
      void quickSort(vector<int>& arr, int low, int high) {
          // code here
             if (low < high) {
          int pIndex = partition(arr, low, high);
          quickSort(arr, low, pIndex - 1);
          quickSort(arr, pIndex + 1, high);
           }
      }
    public:
      // Function that takes last element as pivot, places the pivot element at
      // its correct position in sorted array, and places all smaller elements
      // to left of pivot and all greater elements to right of pivot.
      int partition(vector<int>& arr, int low, int high) {
          // code here
          int n=arr.size();
           int pivot = arr[low];
      int i = low;
      int j = high;
      while (i < j) {
          while (arr[i] <= pivot && i < high) {
              i++;
          }
  
          while (arr[j] > pivot && j > low ) {
              j--;
          }
          if (i < j) swap(arr[i], arr[j]);
      }
      swap(arr[low], arr[j]);
      return j;
      }
  };
Union of Arrays with Duplicates
Given two arrays a[] and b[], the task is to find the number of elements in the union between these two arrays.
The Union of the two arrays can be defined as the set containing distinct elements from both arrays. If there are repetitions, then only one element occurrence should be there in the union.


Examples
Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3]
Output: 5
Explanation: Union set of both the arrays will be 1, 2, 3, 4 and 5. So count is 5.
Input: a[] = [85, 25, 1, 32, 54, 6], b[] = [85, 2] 
Output: 7
Explanation: Union set of both the arrays will be 85, 25, 1, 32, 54, 6, and 2. So count is 7.

class Solution {
  public:
    // Function to return the count of number of elements in union of two arrays.
    int findUnion(vector<int>& a, vector<int>& b) {
        // code here

        // Use a set to store unique elements
        set<int> uniqueElements;
        
        // Insert all elements of the first array into the set
        for (int num : a) {
            uniqueElements.insert(num);
        }
        
        // Insert all elements of the second array into the set
        for (int num : b) {
            uniqueElements.insert(num);
        }
        
        // The size of the set is the count of unique elements in the union
        return uniqueElements.size();
    }
};
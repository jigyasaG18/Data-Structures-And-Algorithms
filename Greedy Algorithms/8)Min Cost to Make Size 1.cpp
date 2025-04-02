Min Cost to Make Size 1
Given an array, arr[]. You need to reduce size of array to one. You are allowed to select a pair of integers and remove the larger one of these two. This decreases the array size by 1. Cost of this operation is equal to value of smaller one. Find out minimum sum of costs of operations needed to convert the array into a single element.

Examples: 
Input: arr[] = [4, 3, 2]
Output: 4
Explanation: Choose (4, 2) so 4 is removed, new array = {2, 3}. Now choose (2, 3) so 3 is removed. So total cost = 2 + 2 = 4

Input: arr[] = [3, 4]
Output: 3
Explanation: Choose 3, 4, so cost is 3. 

Input: arr[] = [1]
Output: 0
Explanation: The array is already of size one, so no operations are needed.

class Solution {
    public:
  
      int cost(vector<int>& arr) {
          // code here
          int n=arr.size();
          if(n==1) return 0;
          sort(arr.begin(),arr.end());
          return arr[0]*(n-1);
      }
  };
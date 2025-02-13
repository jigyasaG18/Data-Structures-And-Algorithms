Friendly Array
Numbers have a measure of friendliness defined as the absolute difference between them. Given an circular array of integers arr[], calculate the friendliness of the array. Friendliness is the sum of the absolute differences between each element and its closest friend in the array.

Examples:
Input: arr[] = [4, 1, 5]
Output: 8
Explanation: The sum of absolute differences with closest neighbors is |4-1| + |1-5| + |5-4| = 8.

Input: arr[] = [1, 1, 1]
Output: 0
Explanation: All elements are identical, so the sum of differences is zero.

class Solution {
    public:
      int calculateFriendliness(vector<int>& arr) {
          // code here
          int n=arr.size();
          int sum=0;
          int lastelediff=0;
          int j=0;
          for(int i=0;i<n-1;i++){
              sum += abs(arr[i]-arr[i+1]);
          }
          lastelediff += abs(arr[n-1]-arr[j]);
          return (sum+lastelediff);
      }
  };
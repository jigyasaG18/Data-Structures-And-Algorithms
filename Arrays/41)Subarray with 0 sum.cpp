Subarray with 0 sum
Given an array of integers, arr[]. Find if there is a subarray (of size at least one) with 0 sum. Return true/false depending upon whether there is a subarray present with 0-sum or not. 

Examples:
Input: arr[] = [4, 2, -3, 1, 6]
Output: true
Explanation: 2, -3, 1 is the subarray with a sum of 0.

Input: arr = [4, 2, 0, 1, 6]
Output: true
Explanation: 0 is one of the element in the array so there exist a subarray with sum 0.

Input: arr = [1, 2, -1]
Output: false

class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        // Your code here
        int n=arr.size();
        int sum=0;
        unordered_map<int,int>mpp;
        for(int i=0;i<n;i++){
            sum += arr[i];
//If the prefix sum is zero or already exists in the map, return true
            if(sum==0) return true;
           if(mpp.find(sum) != mpp.end()){
               return true;
           }
            else mpp[sum]++;
        }
        return false;
    }
};
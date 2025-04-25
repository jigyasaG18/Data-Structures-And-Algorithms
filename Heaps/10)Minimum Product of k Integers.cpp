Minimum Product of k Integers
Given an array arr of  positive integers. You need to return the minimum product of k integers of the given array.

Examples:
Input: arr[] = [1, 2, 3, 4, 5], k = 2
Output: 2
Explanation: We will get the minimum product after multiplying 1 and 2 that is 2. So, the answer is 2.

Input: arr[] = [9, 10, 8], k = 3
Output: 720
Explanation: We have to multiply all the numbers.

class Solution {
    public:
      int minProduct(vector<int> &arr, int k) {
          // Complete the function
          int n=arr.size();
          priority_queue<int>pq;
          for(int i=0;i<n;i++){
              pq.push(arr[i]);
              if(pq.size()>k) pq.pop();
          }
          long long int pdt=1;
          while(!pq.empty()){
              pdt*=pq.top();
              pdt%=1000000007;
              pq.pop();
          }
          return pdt;
      }
  };
Longest Bitonic Subsequence
Given an array of positive integers. Find the maximum length of Bitonic subsequence. 
A subsequence of array is called Bitonic if it is first strictly increasing, then strictly decreasing. Return the maximum length of bitonic subsequence.
Note : A strictly increasing or a strictly decreasing sequence should not be considered as a bitonic sequence

Examples :
Input: n = 5, nums[] = [1, 2, 5, 3, 2]
Output: 5
Explanation: The sequence {1, 2, 5} is increasing and the sequence {3, 2} is decreasing so merging both we will get length 5.

Input: n = 8, nums[] = [1, 11, 2, 10, 4, 5, 2, 1]
Output: 6
Explanation: The bitonic sequence {1, 2, 10, 4, 2, 1} has length 6.

Input: n = 5, nums[] = [10, 20, 30]
Output: 0
Explanation: The decreasing or increasing part cannot be empty

Input: n = 3, nums[] = [10, 10, 10]
Output: 0
Explanation: The subsequences must be strictly increasing or decreasing

class Solution {
    public:
      int LongestBitonicSequence(int n, vector<int> &nums) {
          // code here
            if (n < 2) return 0; // If there are fewer than 2 elements, no bitonic sequence is possible.
          vector<int>dp1(n,1);
          int maxi=0;
          for(int i=0;i<n;i++){
              for(int prev=0;prev<i;prev++){
                  if(nums[prev]<nums[i] && 1+dp1[prev]>dp1[i]){
                      dp1[i]=1+dp1[prev];
                  }
              }
      }
      vector<int>dp2(n,1);
          for(int i=n-1;i>=0;i--){
              for(int prev=n-1;prev>i;prev--){
                  if(nums[prev]<nums[i] && 1+dp2[prev]>dp2[i]){
                      dp2[i]=1+dp2[prev];
                  }
              }
             
      }
      // Step 3: Find the maximum length of the bitonic sequence
      for (int i = 0; i < n; i++) {
          // A valid bitonic sequence requires both parts to have at least length 2
          if (dp1[i] > 1 && dp2[i] > 1) {
              maxi = max(maxi, dp1[i] + dp2[i] - 1); // -1 to correct double counting of nums[i]
          }
      }
      
      return maxi > 1 ? maxi : 0; // Return 0 if there's no valid bitonic sequence
      }
  };  
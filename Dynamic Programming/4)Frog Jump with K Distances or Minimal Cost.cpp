Frog Jump with K Distances or Minimal Cost 
Given an array arr[] of size n, where arr[i] denotes the height of ith stone. Geek starts from stone 0 and from stone i, he can jump to stones i + 1, i + 2, … i + k. The cost for jumping from stone i to stone j is abs(arr[i] – arr[j]). Find the minimum cost for Geek to reach the last stone.

Example:
Input: k = 3, arr[]= [10, 30, 40, 50, 20]
Output: 30
Explanation: Geek will follow the path 1->2->5, the total cost would be |10-30| + |30-20| = 30, which is minimum.

Input: k = 1, arr[]= [10, 20, 10]
Output: 20
Explanation: Geek will follow the path 1->2->3, the total cost would be |10 - 20| + |20 - 10| = 20.

class Solution {
    public:
      int minimizeCost(int k, vector<int>& arr) {
          // Code here
          int n=arr.size();
          vector<int>dp(n+1,-1);
          dp[0]=0;
          for(int i=1;i<n;i++){
              int minsteps=INT_MAX;
              for(int j=1;j<=k;j++){
                  if(i-j>=0){
                      int jumps=dp[i-j]+abs(arr[i]-arr[i-j]);
                      minsteps=min(minsteps,jumps);
                  }
              }
              dp[i]=minsteps;
          }
          return dp[n-1];
      }
  };
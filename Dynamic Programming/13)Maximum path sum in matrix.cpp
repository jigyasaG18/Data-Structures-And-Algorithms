You are given a matrix mat[][] of size n x m where each element is a positive integer. Starting from any cell in the first row, you are allowed to move to the next row, but with specific movement constraints. From any cell (r, c) in the current row, you can move to any of the three possible positions :
(r+1, c-1) — move diagonally to the left.
(r+1, c) — move directly down.
(r+1, c+1) — move diagonally to the right.
Find the maximum sum of any path starting from any column in the first row and ending at any column in the last row, following the above movement constraints.

Examples :
Input: mat[][] = [[3, 6, 1], [2, 3, 4], [5, 5, 1]]
Output: 15
Explaination: The best path is (0, 1) -> (1, 2) -> (2, 1). It gives the maximum sum as 15.

Input: mat[][] = [[2, 1, 1], [1, 2, 2]]
Output: 4
Explaination: The best path is (0, 0) -> (1, 1). It gives the maximum sum as 4.

Input: mat[][] = [[25]]
Output: 25
Explaination: (0, 0) is the only cell in mat[][], so maximum path sum will be 25.

1st Way:- MEMOIZATION 
class Solution {
    public:
    int func(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &matrix){
      int n=matrix.size();
      int m=matrix[0].size();
      if(j<0 || j>=m) return -1e9;
      if(i==0) return matrix[0][j];
      if(dp[i][j]!=-1) return dp[i][j];
      int up=matrix[i][j]+func(i-1,j,dp,matrix);
      int ld=matrix[i][j]+func(i-1,j-1,dp,matrix);
      int rd=matrix[i][j]+func(i-1,j+1,dp,matrix);
      return dp[i][j]=max(up,max(ld,rd));
  }
      int maximumPath(vector<vector<int>>& mat) {
          // code here
           int n=mat.size();
           int m=mat[0].size();
          vector<vector<int>>dp(n,vector<int>(m,-1));
          int maxPathSum = -1e9;
          // Start from each column in the first row
          for (int j = 0; j < m; j++) {
              maxPathSum = max(maxPathSum, func(n - 1, j, dp, mat));
          }
  
          return maxPathSum; // Return the overall maximum falling path sum
      }
  };

2nd Way:- TABULATION
class Solution {
    public:
      int maximumPath(vector<vector<int>>& mat) {
          // code here
          int n=mat.size();
          int m=mat[0].size();
          vector<vector<int>>dp(n,vector<int>(m,0));
          for(int j=0;j<m;j++){
              dp[0][j]=mat[0][j];
          }
          for(int i=1;i<n;i++){
              for(int j=0;j<m;j++){
                  int up=mat[i][j]+dp[i-1][j];
                  int ld=mat[i][j];
                  if(j-1>=0){
                      ld+=dp[i-1][j-1];
                  } 
                  else{
                      ld+= -1e9;
                  }
                  int rd=mat[i][j];
                  if(j+1<m){
                      rd+=dp[i-1][j+1];
                  } 
                  else{
                      rd+= -1e9;
                  }
                  dp[i][j]=max(up,max(ld,rd));
              }
          }
          int maxi= -1e9;
          for(int j=0;j<m;j++){
              maxi=max(maxi,dp[n-1][j]);
          }
          return maxi;
      }
  };

3rd Way:- SPACE OPTIMIZATION
class Solution {
    public:
      int maximumPath(vector<vector<int>>& mat) {
          // code here
           int n = mat.size();
           int m=mat[0].size();
      if (n == 0) return 0;
      vector<int> prev(m, 0);
      vector<int> curr(m, 0);
      // Initialize the first row
      for (int j = 0; j < m; j++) {
          prev[j] = mat[0][j];
      }
      // Dynamic programming to find max path sum
      for (int i = 1; i < n; i++) {
          for (int j = 0; j < m; j++) {
              // Up
              int up = mat[i][j] + prev[j];
              
              // Left Down (diagonal left)
              int ld = mat[i][j];
              if (j - 1 >= 0) {
                  ld += prev[j - 1];
              } else {
                  ld += -1e9; // If out of bounds, use a large negative number
              }
              
              // Right Down (diagonal right)
              int rd = mat[i][j];
              if (j + 1 < m) {
                  rd += prev[j + 1];
              } else {
                  rd += -1e9; // If out of bounds, use a large negative number
              }
              // Current best for (i, j)
              curr[j] = max(up, max(ld, rd));
          }
          prev = curr; // Move to the next row
      }
      // Find the maximum value in the last row
      int maxi = -1e9;
      for (int j = 0; j < m; j++) {
          maxi = max(maxi, prev[j]);
      }
      return maxi;
      }
  };
Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.

Example 1:
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Example 2:
Input: grid = [[1,2,3],[4,5,6]]
Output: 12

1st Way:- MEMOIZATION
class Solution {
    public:
    int func(int i,int j,vector<vector<int>>& mat,vector<vector<int>>&dp){
            if (i == 0 && j == 0) return mat[0][0];
        if (i < 0 || j < 0) return 1e9; // Return a large value to represent infinity
            if (dp[i][j] != -1) return dp[i][j];
    
            int up = mat[i][j] + func(i - 1, j, mat, dp);
            int left = mat[i][j] + func(i, j - 1, mat, dp);
    
            return dp[i][j] = min(up, left);
        }
        int minPathSum(vector<vector<int>>& grid) {
            int n=grid.size();
            int m=grid[0].size();
            vector<vector<int>>dp(n,vector<int>(m,-1));
            return func(n-1,m-1,grid,dp);
        }
    };

2nd Way:- TABULATION
class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
            vector<vector<int>> dp(n, vector<int>(m, -1));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i == 0 && j == 0)
                        dp[i][j] = grid[0][0];
                    else {
                        int up=grid[i][j];
                        int left=grid[i][j];
                    if(i>0) up += dp[i - 1][j];
                    else up+=1e9;
                    if(j>0) left += dp[i][j-1];
                    else left+=1e9;
                        dp[i][j] = min(up, left);
                    }
                }
            }
            return dp[n - 1][m - 1];
        }
    };

3rd Way:- SPACE OPTIMIZATION
class Solution {
    public:
        int minPathSum(vector<vector<int>>& grid) {
            int n = grid.size();
            int m = grid[0].size();
            vector<int>prev(m,0);
            for (int i = 0; i < n; i++) {
                vector<int>curr(m,0);
                for (int j = 0; j < m; j++) {
                    if (i == 0 && j == 0)
                        curr[j] = grid[i][j];
                    else {
                        int up=grid[i][j];
                        int left=grid[i][j];
                    if(i>0) up += prev[j];
                    else up+=1e9;
                    if(j>0) left += curr[j-1];
                    else left+=1e9;
                        curr[j] = min(up, left);
                    }
                }
                prev=curr;
            }
            return prev[m - 1];
        }
    };
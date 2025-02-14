Grid Unique Paths II 
You are given an m x n integer array grid. There is a robot initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
An obstacle and space are marked as 1 or 0 respectively in grid. A path that the robot takes cannot include any square that is an obstacle.
Return the number of possible unique paths that the robot can take to reach the bottom-right corner.
The testcases are generated so that the answer will be less than or equal to 2 * 109.

Example 1:
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right

Example 2:
Input: obstacleGrid = [[0,1],[0,0]]
Output: 1

1st Way:- MEMOIZATION
class Solution {
    public:
    int mod=1e9+7;
    int func(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
    if(i>=0 && j>=0 && grid[i][j] == 1) return 0;
    if(i== 0 && j==0) return 1;
    if(i<0 || j<0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
        
            int up = func(i-1, j, grid, dp);
            int left = func(i, j-1, grid, dp);
    
            return dp[i][j] = (up+left) % mod;
        }
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int n=obstacleGrid.size();
            int m=obstacleGrid[0].size();
            vector<vector<int>>dp(n,vector<int>(m,-1));
            return func(n-1,m-1,obstacleGrid,dp);
        }
    };

2nd Way:- TABULATION
class Solution {
    public:
    int mod = (int)1e+7;
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int m=obstacleGrid.size();
            int n=obstacleGrid[0].size();
             vector<vector<int>>dp(m,vector<int>(n,-1));
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(i>=0 && j>=0 && obstacleGrid[i][j]==1) dp[i][j]=0;
                    else if(i==0 && j==0) dp[i][j] = 1; 
                    else{
                        int up=0;
                        int left=0;
                        if(i>0) up=dp[i-1][j];
                        if(j>0) left=dp[i][j-1];
                        dp[i][j]=(up+left)%mod;
                    }
                }
            }
            return dp[m-1][n-1];
        }
    };

3rd Way:- SPACE OPTIMIZATION
class Solution {
    public:
    int mod = (int)1e9+7;
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            int m=obstacleGrid.size();
            int n=obstacleGrid[0].size();
             vector<int>prev(n,0);
            for(int i=0;i<m;i++){
                vector<int>temp(n,0);
                for(int j=0;j<n;j++){
                    if(i>=0 && j>=0 && obstacleGrid[i][j]==1){
                    temp[j]=0;
                    continue;
                    }
                    else if(i==0 && j==0) {
                        temp[j]=1;
                        continue;
                    }
                    int up=0;
                    int left=0;
                    if(i>0) up=prev[j];
                    if(j>0) left=temp[j-1];
                    temp[j]=(up+left)%mod;
                }
                prev=temp;
            }
            return prev[n-1];
        }
    };
Minimum Falling Path Sum
Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.
A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

Example 1:
Input: matrix = [[2,1,3],[6,5,4],[7,8,9]]
Output: 13
Explanation: There are two falling paths with a minimum sum as shown.

Example 2:
Input: matrix = [[-19,57],[-40,-5]]
Output: -59
Explanation: The falling path with a minimum sum is shown.

1st Way:- MEMOIZATION 
class Solution {
    public:
    int func(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &mat){
        int n=mat.size();
        if(j<0 || j>=n) return 1e9;
        if(i==0) return mat[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up=mat[i][j]+func(i-1,j,dp,mat);
        int ld=mat[i][j]+func(i-1,j-1,dp,mat);
        int rd=mat[i][j]+func(i-1,j+1,dp,mat);
        return dp[i][j]=min(up,min(ld,rd));
    }
        int minFallingPathSum(vector<vector<int>>& matrix) {
            int n=matrix.size();
            vector<vector<int>>dp(n,vector<int>(n,-1));
            int minPathSum = 1e9; // Initialize minPathSum to a large value
            // Start from each column in the first row
            for (int j = 0; j < n; j++) {
                minPathSum = min(minPathSum, func(n - 1, j, dp, matrix));
            }
    
            return minPathSum; // Return the overall minimum falling path sum
        }
    };

2nd Way:- TABULATION
class Solution {
    public:
        int minFallingPathSum(vector<vector<int>>& matrix) {
            int n=matrix.size();
            vector<vector<int>>dp(n,vector<int>(n,0));
            for(int j=0;j<n;j++){
                dp[0][j]=matrix[0][j];
            }
            for(int i=1;i<n;i++){
                for(int j=0;j<n;j++){
                    int up=matrix[i][j]+dp[i-1][j];
                    int ld=matrix[i][j];
                    if(j-1>=0){
                        ld+=dp[i-1][j-1];
                    } 
                    else{
                        ld+= 1e9;
                    }
                    int rd=matrix[i][j];
                    if(j+1<n){
                        rd+=dp[i-1][j+1];
                    } 
                    else{
                        rd+= 1e9;
                    }
                    dp[i][j]=min(up,min(ld,rd));
                }
            }
            int mini= 1e9;
            for(int j=0;j<n;j++){
                mini=min(mini,dp[n-1][j]);
            }
            return mini;
        }
    };

3rd Way:- SPACE OPTIMIZATION
class Solution {
    public:
        int minFallingPathSum(vector<vector<int>>& matrix) {
            int n=matrix.size();
            vector<int>prev(n,0);
            vector<int>curr(n,0);
            for(int j=0;j<n;j++){
                prev[j]=matrix[0][j];
            }
            for(int i=1;i<n;i++){
                for(int j=0;j<n;j++){
                    int up=matrix[i][j]+prev[j];
                    int ld=matrix[i][j];
                    if(j-1>=0){
                        ld+=prev[j-1];
                    } 
                    else{
                        ld+= 1e9;
                    }
                    int rd=matrix[i][j];
                    if(j+1<n){
                        rd+=prev[j+1];
                    } 
                    else{
                        rd+= 1e9;
                    }
                    curr[j]=min(up,min(ld,rd));
                }
                prev=curr;
            }
            int mini= 1e9;
            for(int j=0;j<n;j++){
                mini=min(mini,prev[j]);
            }
            return mini;
        }
    };
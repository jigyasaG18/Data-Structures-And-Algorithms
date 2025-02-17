Minimum path sum in Triangular Grid
Given a triangle array, return the minimum path sum from top to bottom.
For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

Example 1:
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

Example 2:
Input: triangle = [[-10]]
Output: -10

1st Way:- MEMOIZATION
class Solution {
    public:
    int func(int i,int j,vector<vector<int>>&mat,vector<vector<int>>&dp){
            int n=mat.size();
            int m=mat[0].size();
        if(i==n-1) return mat[n-1][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int down=mat[i][j]+func(i+1,j,mat,dp);
        int diagonal=mat[i][j]+func(i+1,j+1,mat,dp);
        return dp[i][j]=min(down,diagonal);
    }
        int minimumTotal(vector<vector<int>>& triangle) {
            int n=triangle.size();
            int m=triangle[0].size();
            vector<vector<int>>dp(n,vector<int>(n,-1));
            return func(0,0,triangle,dp);
        }
    };

2nd Way:- TABULATION
class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            int n=triangle.size();
            vector<vector<int>>dp(n,vector<int>(n,0));
            for(int j=0;j<n;j++) dp[n-1][j]=triangle[n-1][j];
            for(int i=n-2;i>=0;i--){
                for(int j=i;j>=0;j--){
                    int d=dp[i+1][j]+triangle[i][j];
                    int dg=dp[i+1][j+1]+triangle[i][j];
                    dp[i][j]=min(d,dg);
                }
            }
            return dp[0][0];
        }
    };

3rd Way:- SPACE OPTIMIZATION
class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            int n=triangle.size();
            vector<int>front(n,0);
            vector<int>curr(n,0);
            for(int j=0;j<n;j++) front[j]=triangle[n-1][j];
            for(int i=n-2;i>=0;i--){
                for(int j=i;j>=0;j--){
                    int d=front[j]+triangle[i][j];
                    int dg=front[j+1]+triangle[i][j];
                    curr[j]=min(d,dg);
                }
                front=curr;
            }
            return front[0];
        }
    };
Chocolates Pickup/Cherry Pickup-II/Ninja and his Friends
You are given an n rows and m cols matrix grid representing a field of chocolates where grid[i][j] represents the number of chocolates that you can collect from the (i, j) cell.
You have two robots that can collect chocolates for you:
Robot #1 is located at the top-left corner (0, 0), and
Robot #2 is located at the top-right corner (0, cols - 1).
Return the maximum number of chocolates collection using both robots by following the rules below:
From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
When any robot passes through a cell, It picks up all chocolates, and the cell becomes an empty cell.
When both robots stay in the same cell, only one takes the chocolates.
Both robots cannot move outside of the grid at any moment.
Both robots should reach the bottom row in grid.

Example:
Input: n = 4, m = 3
grid = [[3,1,1],[2,5,1],[1,5,5],[2,1,1]]
Output: 24
Explanation: Path of robot #1 and #2 are described in color green and blue respectively. Chocolates taken by Robot #1, (3 + 2 + 5 + 2) = 12. Chocolates taken by Robot #2, (1 + 5 + 5 + 1) = 12. Total of Chocolates: 12 + 12 = 24.

1st Way:- MEMOIZATION
class Solution {
    public:
    int solve1(int i1,int j1,int j2,vector<vector<int>>&grid,vector<vector<vector<int>>> &dp){
        int n=grid.size();
        int m=grid[0].size();
        if(j1<0 || j2<0 || j1>=m || j2>=m) return -1e9;
        if(dp[i1][j1][j2]!=-1) return dp[i1][j1][j2];
        if(i1==n-1){
            if(j1==j2) return grid[i1][j1];
            else return grid[i1][j1]+grid[i1][j2];
        }
        int maxi=-1e9;
        for(int dj1=-1;dj1<=1;dj1++){
            for(int dj2=-1;dj2<=1;dj2++){
                if(j1==j2){
                    maxi=max(maxi,grid[i1][j1]+solve1(i1+1,j1+dj1,j2+dj2,grid,dp));
            }
            else{
                maxi=max(maxi,grid[i1][j1]+grid[i1][j2]+solve1(i1+1,j1+dj1,j2+dj2,grid,dp));
            }
        }
        }
        dp[i1][j1][j2]=maxi;
        return maxi;
    }
      int solve(int n, int m, vector<vector<int>>& grid) {
          // code here
          vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
          return solve1(0,0,m-1,grid,dp);
      }
  };

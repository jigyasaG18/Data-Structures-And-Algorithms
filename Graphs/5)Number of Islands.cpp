Number of Islands

4 directions are connected
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3

BFS TRAVERSAL
#include <vector>
using namespace std;

class Solution {
   void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> grid){
        int n=grid.size();
        int m=grid[0].size();
         vis[row][col] = 1; // Mark current cell as visited
        
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

        // Directions for right, down, left, up (not diagonals)
        int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        for (int i = 0; i < 4; i++) {
            int nrow = row + directions[i][0];
            int ncol = col + directions[i][1];
            
            // Check if the new cell is within bounds, not visited, and is land
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
                   vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
            }
        }
    }
   }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0; // Edge case - empty grid
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0)); // Visited array

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                // If we find an unvisited island cell, perform BFS
                if (!vis[row][col] && grid[row][col] == '1') {
                    cnt++;
                    bfs(row, col, vis, grid); // Explore the entire island
                }
            }
        }
        return cnt; // Return the count of islands
    }
};

DFS TRAVERSAL
#include <vector>
using namespace std;

class Solution {
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vis[row][col] = 1; // Mark current cell as visited
        
        // Directions for right, down, left, up (not diagonals)
        int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        for (int i = 0; i < 4; i++) {
            int nrow = row + directions[i][0];
            int ncol = col + directions[i][1];
            
            // Check if the new cell is within bounds, not visited, and is land
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
                dfs(nrow, ncol, vis, grid); // Continue DFS
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0; // Edge case - empty grid
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0)); // Visited array

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                // If we find an unvisited island cell, perform DFS
                if (!vis[row][col] && grid[row][col] == '1') {
                    cnt++;
                    dfs(row, col, vis, grid); // Explore the entire island
                }
            }
        }
        return cnt; // Return the count of islands
    }
};


8 directions are connected
Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of '0's (Water) and '1's(Land). Find the number of islands.
Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Examples:
Input: grid = [[0,1],[1,0],[1,1],[1,0]]
Output: 1
Explanation: The grid is- All lands are connected.

Input: grid = [[0,1,1,1,0,0,0],[0,0,1,1,0,1,0]]
Output: 2
Expanation: The grid is- There are two islands :- one is colored in "blue" and other in "red".

BFS TRAVERSAL
class Solution {
    private:
      void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> grid){
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=1;
        queue<pair<int,int>>q;
        q.push({row,col});
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();

            //traverse neighbours and mark if its a land
            for(int delrow=-1;delrow<=1;delrow++){
                for(int delcol=-1;delcol<=1;delcol++){
                    int nrow=row+delrow;
                    int ncol=col+delcol;

                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]
                    && grid[nrow][ncol]=='1'){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
      }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    cnt++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return cnt;
    }
};

DFS TRAVERSAL
void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vis[row][col] = 1; // Mark current cell as visited
        
          // traverse neighbours and mark if its a land
        for (int delrow = -1; delrow <= 1; delrow++) {
            for (int delcol = -1; delcol <= 1; delcol++) {
                int nrow = row + delrow;
                int ncol = col + delcol;

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    !vis[nrow][ncol] && grid[nrow][ncol] == '1') {
                    dfs(nrow, ncol, vis, grid);
                }
            }
        }
    }
  public:
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        if (n == 0) return 0; // Edge case - empty grid
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0)); // Visited array

        for (int row = 0; row < n; row++) {
            for (int col = 0; col < m; col++) {
                // If we find an unvisited island cell, perform DFS
                if (!vis[row][col] && grid[row][col] == '1') {
                    cnt++;
                    dfs(row, col, vis, grid); // Explore the entire island
                }
            }
        }
        return cnt; // Return the count of islands
    }
};
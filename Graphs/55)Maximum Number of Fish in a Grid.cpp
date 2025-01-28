Maximum Number of Fish in a Grid
You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:
A land cell if grid[r][c] = 0, or A water cell containing grid[r][c] fish, if grid[r][c] > 0.
A fisher can start at any water cell (r, c) and can do the following operations any number of times:
Catch all the fish at cell (r, c), or Move to any adjacent water cell.
Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.
An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.

Example 1:
Input: grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
Output: 7
Explanation: The fisher can start at cell (1,3) and collect 3 fish, then move to cell (2,3) and collect 4 fish.

Example 2:
Input: grid = [[1,0,0,0],[0,0,0,0],[0,0,0,0],[0,0,0,1]]
Output: 1
Explanation: The fisher can start at cells (0,0) or (3,3) and collect a single fish. 

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxfish = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int delrow[] = {-1, 0, 1, 0};  // Directions for rows
        int delcol[] = {0, 1, 0, -1};  // Directions for cols

        // Iterate through the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // If we find a water cell that hasn't been visited
                if (grid[i][j] > 0 && vis[i][j] == 0) { 
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    vis[i][j] = 1;
                    int sum = 0;

                    // Perform BFS from the cell (i, j)
                    while (!q.empty()) {
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();

                        sum += grid[row][col];  // Add fish count

                        // Explore all 4 directions
                        for (int k = 0; k < 4; k++) {
                            int nrow = row + delrow[k];
                            int ncol = col + delcol[k];

// Check if the adjacent cell is within bounds, not visited, and contains fish
 if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] > 0) {
                                vis[nrow][ncol] = 1; // Mark as visited
                                q.push({nrow, ncol}); // Add to queue
                            }
                        }
                    }
                    maxfish = max(maxfish, sum); // Update max fish count
                }
            }
        }
        return maxfish; // Return the maximum fish caught
    }
};
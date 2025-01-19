Trapping Rain Water II
Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.

Example 1:
Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
Output: 4
Explanation: After the rain, water is trapped between the blocks.
We have two small ponds 1 and 3 units trapped.
The total volume of water trapped is 4.

Example 2:
Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
Output: 10

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
         int n = heightMap.size();
        int m = heightMap[0].size();

        // pair<int, pair<int, int>> 
        //{height, {r, c}}
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

        vector<vector<int>> vis(n, vector<int>(m));

        //first and last column
        //first and last row
        //Set the boundary element as visited
        // Add all boundary cells to the priority queue
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i == 0 || i == n - 1 || j == 0 || j == m - 1){
                    pq.push({heightMap[i][j], {i, j}});
                    vis[i][j] = 1; // Mark boundary cells as visited
                }
            }
        }

        int total=0;
        while(!pq.empty()){
            int h = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            int delrow[] = {-1, 0, 1, 0};
            int delcol[] = {0, -1, 0, 1};
            for(int i=0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol]){
                    total+=max(0, h-heightMap[nrow][ncol]);
                    pq.push({max(h, heightMap[nrow][ncol]), {nrow, ncol}});
                    vis[nrow][ncol] = 1;
                }
            }
        }
        return total;
    }
};
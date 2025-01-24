Swim in Rising Water
You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).
The rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.
Return the least time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

Example 1:
Input: grid = [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.
You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.

Example 2:
Input: grid = [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation: The final route is shown.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.

1st Way:-
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class DisjointSet
{
    vector<int> parent;
public:
    DisjointSet(int n)
    {
        parent.resize(n);  // No need for +1 since we're using 0-based indexing.
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int findUPar(int x)
    {
        if (x == parent[x])
            return x;
        return parent[x] = findUPar(parent[x]);
    }

    void unionBySize(int u, int v)
    {
        int up_u = findUPar(u);
        int up_v = findUPar(v);
        if (up_u != up_v)
            parent[up_u] = up_v; // Simple union for this case; sizes aren't mandatory for a 2D grid scenario here.
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> levels;

        // Fill the levels vector with all the unique water levels
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                levels.push_back(grid[i][j]);

        // Sort the water levels
        sort(levels.begin(), levels.end());

        DisjointSet ds(n * n);
        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, -1, 0, 1};
        
        // Min heap can also be used to handle cell popping efficiently
        vector<vector<bool>> visited(n, vector<bool>(n, false));

        for (int time : levels) {
            // Connect cells with the current water level within the range
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == time) {
                        int node = i * n + j;
                        visited[i][j] = true; // Mark this cell as visited

                        // Connect with adjacent cells if within bounds and their levels are <= time
                        for (int d = 0; d < 4; d++) {
                            int nrow = i + delrow[d];
                            int ncol = j + delcol[d];

                            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < n && visited[nrow][ncol]) {
                                int adjnode = nrow * n + ncol;
                                ds.unionBySize(node, adjnode);
                            }
                        }

                        // Check if we can connect the start (0,0) and end (n-1,n-1)
                        if (ds.findUPar(0) == ds.findUPar(n * n - 1)) {
                            return time; // The result is the current level of water
                        }
                    }
                }
            }
        }

        return -1; // This shouldn't happen in valid input according to the problem's constraints.
    }
};

2nd Way:- Using Dijkstra's Algorithm
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        vector<vector<int>> dist(n,vector<int>(n,INT_MAX));

        pq.push({grid[0][0],{0,0}});
        dist[0][0]=grid[0][0];

        int drow[]={0,1,-1,0};
        int dcol[]={1,0,0,-1};

        while(!pq.empty()){
            int dis=pq.top().first;
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            pq.pop();

            if(r==n-1 && c==n-1){
                return dis;
            }

            for(int i=0;i<4;i++){
                int newr=r+drow[i];
                int newc=c+dcol[i];

                if(newr>-1 && newr<n && newc<n && newc>-1){
                    int length=max(grid[newr][newc],dis);
                    if(length<dist[newr][newc]){
                        dist[newr][newc]=length;
                        pq.push({length,{newr,newc}});
                    }
                }

            }
        }

        return -1;
    }
};
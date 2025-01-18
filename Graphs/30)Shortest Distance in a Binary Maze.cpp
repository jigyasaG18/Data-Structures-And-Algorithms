Shortest Distance in a Binary Maze
Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.
A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

Example 1:
Input: grid = [[0,1],[1,0]]
Output: 2

Example 2:
Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4

Example 3:
Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1

1st Way:-
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
    // Source and destination points
        pair<int, int> source = {0, 0};
        pair<int, int> destination = {n-1, n-1};
if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;
if(source.first==destination.first && source.second==destination.second) return 1;
queue<pair<int, pair<int,int>>>q;
q.push({1,{source.first,source.second}});
vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
dist[source.first][source.second]=0;
while(!q.empty()){
    auto it=q.front();
    q.pop();
    int distance=it.first;
    int row=it.second.first;
    int col=it.second.second;
    
    for(int delrow=-1;delrow<=1;delrow++){
    for(int delcol=-1;delcol<=1;delcol++){
        int nrow=row+delrow;
        int ncol=col+delcol;
        
if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==0 && 1+distance<dist[nrow][ncol])
{
    dist[nrow][ncol]=1+distance;
if(nrow==destination.first && ncol==destination.second) return 1+distance;
q.push({1+distance,{nrow,ncol}});
}    
}
}
}
return -1;
    }
};

2nd Way:-
class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
if(source.first==destination.first && source.second==destination.second) return 0;
        int n=grid.size();
        int m=grid[0].size();
queue<pair<int, pair<int,int>>>q;
q.push({0,{source.first,source.second}});
vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
dist[source.first][source.second]=0;
int delrow[]={-1,0,+1,0};
int delcol[]={0,+1,0,-1};
while(!q.empty()){
    auto it=q.front();
    q.pop();
    int distance=it.first;
    int row=it.second.first;
    int col=it.second.second;
    
    for(int i=0;i<4;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        
if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 && 1+distance<dist[nrow][ncol])
{
    dist[nrow][ncol]=1+distance;
if(nrow==destination.first && ncol==destination.second) return 1+distance;
q.push({1+distance,{nrow,ncol}});
}    }
}
return -1;
    }
};
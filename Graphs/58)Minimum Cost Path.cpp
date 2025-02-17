Minimum Cost Path
Given a square grid of size N, each cell of which contains an integer cost that represents a cost to traverse through that cell, we need to find a path from the top left cell to the bottom right cell by which the total cost incurred is minimum.
From the cell (i,j) we can go (i,j-1), (i, j+1), (i-1, j), (i+1, j).  

Examples :
Input: grid = {{9,4,9,9},{6,7,6,4},{8,3,3,7},{7,4,9,10}}
Output: 43
Explanation: The grid is-
9 4 9 9
6 7 6 4
8 3 3 7
7 4 9 10
The minimum cost is-
9 + 4 + 7 + 3 + 3 + 7 + 10 = 43.

Input: grid = {{4,4},{3,7}}
Output: 14
Explanation: The grid is-
4 4
3 7
The minimum cost is- 4 + 3 + 7 = 14.

class Solution{
    public:
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {       // Code here
           int n=grid.size();
      vector<vector<int>>dist(n, vector<int>(n, 1e9));
        dist[0][0]=grid[0][0];
       int delrow[]={-1, 0, 1, 0};
       int delcol[]={0, 1, 0, -1};
       priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> >q;
       q.push({grid[0][0], {0, 0}});
       while(!q.empty()){
           auto it=q.top();
           q.pop();
           int cost=it.first;
           int row=it.second.first;
           int col=it.second.second;
           if(row==n-1 && col==n-1) return cost;
           for(int i=0; i<4; i++){
               int nrow=row+delrow[i];
               int ncol=col+delcol[i];
               if(ncol>=0 && ncol<n && nrow>=0 && nrow<n && dist[nrow][ncol]>cost+grid[nrow][ncol]){
                   dist[nrow][ncol]=cost+grid[nrow][ncol];
                   q.push({dist[nrow][ncol], {nrow, ncol}});
               }
           }
       }
       return 0;
    }
};
Number of Islands - II 
You are given an empty 2D binary grid grid of size m x n. The grid represents a map where 0's represent water and 1's represent land. Initially, all the cells of grid are water cells (i.e., all the cells are 0's).
We may perform an add land operation which turns the water at position into a land. You are given an array positions where positions[i] = [ri, ci] is the position (ri, ci) at which we should operate the ith operation.
Return an array of integers answer where answer[i] is the number of islands after turning the cell (ri, ci) into a land.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input: m = 3, n = 3, positions = [[0,0],[0,1],[1,2],[2,1]]
Output: [1,1,2,3]
Explanation:
Initially, the 2d grid is filled with water.
- Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land. We have 1 island.
- Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land. We still have 1 island.
- Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land. We have 2 islands.
- Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land. We have 3 islands.

Example 2:
Input: m = 1, n = 1, positions = [[0,0]]
Output: [1]

class DisjointSet{
    vector<int>parent,size;
    public:
    DisjointSet(int n){
        size.resize(n);
        parent.resize(n);
        
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    
    int findUPar(int node){
        if(node==parent[node]) return node;
        return parent[node]=findUPar(parent[node]);
    }
    
    void unionBySize(int u, int v){
        int ulp_u=findUPar(u);
        int ulp_v=findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u]=ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v]=ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet  ds(n*m);
        int vis[n][m];
        memset(vis,0,sizeof vis);
        int cnt=0;
        vector<int>ans;
        for(auto it : operators){
            int row=it[0];
            int col=it[1];
            
        if(vis[row][col] == 1){
            ans.push_back(cnt);
            continue;
        }
        vis[row][col]=1;
        cnt++;
        
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        
        for(int i=0;i<4;i++){
            int adjrow=row+delrow[i];
            int adjcol=col+delcol[i];
            
if(adjrow>=0 && adjrow<n && adjcol>=0 && adjcol<m && vis[adjrow][adjcol]==1){
    int nodeno=row*m+col;
    int adjnodeno=adjrow*m+adjcol;
    
if(ds.findUPar(nodeno) != ds.findUPar(adjnodeno)){
    cnt--;
    ds.unionBySize(nodeno,adjnodeno);
}
}}
        ans.push_back(cnt);
        }
        return ans;
    }
};
Making a Large Island or Maximum Connected Group
You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
Return the size of the largest island in grid after applying this operation.
An island is a 4-directionally connected group of 1s.

Example 1:
Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.

Example 2:
Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: Change the 0 to 1 and make the island bigger, only one island with area = 4.

Example 3:
Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: Can't change any 0 to 1, only one island with area = 4.

class DisjointSet {
public:
    vector<int> parent, size;
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==0) continue;
                int delrow[]={-1,0,+1,0};
                int delcol[]={0,-1,0,+1};
                for(int i=0;i<4;i++){
                    int nrow=row+delrow[i];
                    int ncol=col+delcol[i];

    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
        int nodeno=row*n+col;
        int adjnodeno=nrow*n+ncol;
        ds.unionBySize(nodeno,adjnodeno);
    }
                }
            }
        }

        int mx=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1) continue;
                int delrow[]={-1,0,+1,0};
                int delcol[]={0,-1,0,+1};
                set<int>components;
                for(int i=0;i<4;i++){
                    int nrow=row+delrow[i];
                    int ncol=col+delcol[i];

    if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
        components.insert(ds.findUPar(nrow*n+ncol));
    }
                
        }

        int sizetotal=0;
        for(auto it : components){
            sizetotal+=ds.size[it];
        }
        mx=max(mx,sizetotal+1);
    }
        }
        for(int cellno=0;cellno<n*n;cellno++){
            mx=max(mx,ds.size[ds.findUPar(cellno)]);
        }
        return mx;
        }
};
M-Coloring Problem
You are given an undirected graph consisting of v vertices and a list of edges, along with an integer m. Your task is to determine whether it is possible to color the graph using at most m different colors such that no two adjacent vertices share the same color. Return true if the graph can be colored with at most m colors, otherwise return false.
Note: The graph is indexed with 0-based indexing.

Examples:
Input: v = 4, edges[] = [(0,1),(1,2),(2,3),(3,0),(0,2)], m = 3
Output: true
Explanation: It is possible to color the given graph using 3 colors, for example, one of the possible ways vertices can be colored as follows:
Vertex 0: Color 3
Vertex 1: Color 2
Vertex 2: Color 1
Vertex 3: Color 2

Input: v = 3, edges[] = [(0,1),(1,2),(0,2)], m = 2
Output: false
Explanation: It is not possible to color the given graph using only 2 colors because vertices 0, 1, and 2 form a triangle.

class Solution {
    public:
    bool issafe(int node,int color[],bool graph[101][101],int n,int col){
        for(int k=0;k<n;k++){
            if(k!=node && graph[k][node]==1 && color[k]==col){
                return false;
            }
        }
       return true;
    }
    bool solve(int node,int color[],int m,int N,bool graph[101][101]){
        if(node==N) return true;
        for(int i=1;i<=m;i++){
            if(issafe(node,color,graph,N,i)){
                color[node]=i;
                if(solve(node+1,color,m,N,graph)) return true;
                color[node]=0;
            }
        }
        return false;
    }
      bool graphColoring(int v, vector<pair<int, int>>& edges, int m) {
          // code here
          bool graph[101][101]={false};
          for(auto &edge : edges){
              int u=edge.first;
              int w=edge.second;
              graph[u][w]=true;
              graph[w][u]=true;
          }
          int color[101]={0};
          return solve(0,color,m,v,graph);
      }
  };
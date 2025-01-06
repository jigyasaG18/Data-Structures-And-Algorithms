Introduction to Graphs

1) Graph and Vertices
Given an integer n representing number of vertices. Find out how many undirected graphs (not necessarily connected) can be constructed out of a given n number of vertices.

Example 1:
Input: 2
Output: 2

Example 2:
Input: 5
Output: 1024

class Solution {
  public:
    long long count(int n) {
        // your code here
        int totalEdges = n * (n - 1) / 2;
        // Total graphs = 2^(totalEdges)
        return (long)pow(2, totalEdges);
    }
};

2) Graph Representation in C++
Print adjacency list
Given an undirected graph with V nodes and E edges, create and return an adjacency list of the graph. 0-based indexing is followed everywhere.

Example 1:
Input: V = 5, E = 7
edges = [[0,1], [0,4], [4,1], [4,3], [1,3], [1,2], [3,2]]
Output: 
[[1,4], [0,2,3,4], [1,3], [1,2,4], [0,1,3]]
Explanation:
Node 0 is connected to 1 and 4.
Node 1 is connected to 0,2,3 and 4.
Node 2 is connected to 1 and 3.
Node 3 is connected to 1,2 and 4.
Node 4 is connected to 0,1 and 3.

Example 2:
Input: V = 4, E = 3
edges = [[0,3], [0,2], [2,1]]
Output: 
[[2,3], [2], [0,1], [0]]
Explanation:
Node 0 is connected to 2 and 3.
Node 1 is only connected to 2.
Node 2 is connected to 0 and 1.
Node 3 is only connected to 0.

class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        // Code here
        int n = V;
        int m = edges.size();
         vector<vector<int>>adj(n);
       for (int i=0; i<m; i++){
           int u= edges[i].first;
           int v= edges[i].second;
           adj[u].push_back(v);
           adj[v].push_back(u);
           
       }
       return adj;
    }
};
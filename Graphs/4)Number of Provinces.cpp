Number of Provinces
Given an undirected graph with V vertices. We say two vertices u and v belong to a single province if there is a path from u to v or v to u. Your task is to find the number of provinces.
Note: A province is a group of directly or indirectly connected cities and no other cities outside of the group.

Example 1:
Input:
[
 [1, 0, 1],
 [0, 1, 0],
 [1, 0, 1]
]
Output:
2
Explanation: The graph clearly has 2 Provinces [1,3] and [2]. As city 1 and city 3 has a path between them they belong to a single province. City 2 has no path to city 1 or city 3 hence it belongs to another province.

Example 2:
Input:
[
 [1, 1],
 [1, 1]
]
Output : 1

1st Way:-
//User function Template for C++

class Solution {
  private:
  void dfs(int node, vector<int> adjls[], int vis[]){
      vis[node]=1;
      for(auto it:adjls[node]){
          if(!vis[it]){
              dfs(it,adjls,vis);
          }
      }
  }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<int>adjls[V];
        for(int i=0;i<V;i++){
              for(int j = 0;j<V;j++) {
            if(adj[i][j]==1 && i!=j){
                adjls[i].push_back(j);
                adjls[j].push_back(i);
            }
        }
        }
        int vis[V]={0};
        int cnt=0;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                cnt++;
                dfs(i,adjls,vis);
            }
        }
        return cnt;
    }
};

2nd Way:-
class Solution {
private:
    void dfs(int node, vector<int> adjls[], vector<bool>& vis) {
        vis[node] = true; // Mark the current node as visited
        for (auto it : adjls[node]) { // Iterate through all adjacent nodes
            if (!vis[it]) { // If the adjacent node has not been visited
                dfs(it, adjls, vis); // Recursive DFS call
            }
        }
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> adjls[V]; // Adjacency list representation

        // Build the adjacency list from the isConnected matrix
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) { // Adding edges
                    adjls[i].push_back(j);
                    adjls[j].push_back(i);
                }
            }
        }
        
        vector<bool> vis(V, false); // Visited array
        int cnt = 0; // Count of connected components
        
        // Iterate through all nodes
        for (int i = 0; i < V; i++) {
            if (!vis[i]) { // If not visited, it's a new component
                cnt++;
                dfs(i, adjls, vis); // Perform DFS to mark all reachable nodes
            }
        }
        
        return cnt; // Return total number of connected components
    }
};
Cycle in a Directed Graph
Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as an adjacency list, where adj[i] contains a list of vertices that are directly reachable from vertex i. Specifically, adj[i][j] represents an edge from vertex i to vertex j.

class Solution {
private:

bool dfs(int node, vector<vector<int>> &adj, int vis[], int pathvis[]) {
    vis[node] = 1;   // Mark the current node as visited
    pathvis[node] = 1; // Mark the current node in the recursion stack

    for (auto it : adj[node]) {
        if (!vis[it]) { // If the node has not been visited yet
            if (dfs(it, adj, vis, pathvis)==true) return true; // Recursive DFS
        } else if (pathvis[it]) { // If the node is in the current path
            return true; // Cycle detected
        }
    }

    pathvis[node] = 0; // Unmark the current node from the current path stack
    return false; // No cycle was detected
}
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
     int vis[V] = {0}; // Visited array
    int pathvis[V] = {0}; // Path visited array
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfs(i, adj, vis, pathvis)==true) return true; // Call DFS
        }
    }
    return false; // No cycles detected in any component
    }
};
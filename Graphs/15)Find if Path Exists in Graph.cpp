Find if Path Exists in Graph
There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.
You want to determine if there is a valid path that exists from vertex source to vertex destination.
Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.

Example 1:
Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
Output: true
Explanation: There are two paths from vertex 0 to vertex 2:
- 0 → 1 → 2
- 0 → 2

Example 2:
Input: n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
Output: false
Explanation: There is no path from vertex 0 to vertex 5.

BFS TRAVERSAL:-
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);
        for(auto edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        queue<int>q;
        vector<int>vis(n,0);
        vis[source]=1;
        q.push(source);

        while(!q.empty()){
            int node=q.front();
            q.pop();

            if(node == destination) return true;

            for(int adjnode : adj[node]){
                if(!vis[adjnode]){
                    q.push(adjnode);
                    vis[adjnode]=1;
                }
            }
        }
        return false;
    }
};

DFS TRAVERSAL:-
class Solution {
private:
    bool dfs(vector<vector<int>>& adj, int source, int destination, vector<int>& vis) {
        // If source and destination are the same, a path is found
        if (source == destination)
            return true;
        
        // Mark the current node as visited
        vis[source] = 1;
        
        // Traverse through all adjacent vertices of the current vertex
        for (auto& neighbor : adj[source]) {
            // If the neighbor is not visited, recursively search for a path
            if (!vis[neighbor]) {
                if (dfs(adj, neighbor, destination, vis) == true) {
                    return true; // If a path is found, return true
                }
            }
        }
        return false; // No path found from source to destination
    }
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        // Create an adjacency list representation of the graph
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        // Initialize a vector to keep track of visited vertices
        vector<int> vis(n, 0);
        
        // Call the helper function to find a path from source to destination
        return dfs(adj, source, destination, vis);
    }
};
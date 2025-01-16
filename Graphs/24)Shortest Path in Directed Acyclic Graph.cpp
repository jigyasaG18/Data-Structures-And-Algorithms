Shortest Path in Directed Acyclic Graph 
Given a Directed Acyclic Graph of V vertices from 0 to n-1 and a 2D Integer array(or vector) edges[ ][ ] of length E, where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.
Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.

Examples :
Input: V = 4, E = 2, edges = [[0,1,2], [0,2,1]]
Output: [0, 2, 1, -1]
Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->2 with edge weight 1. There is no way we can reach 3, so it's -1 for 3.

Input: V = 6, E = 7, edges = [[0,1,2], [0,4,1], [4,5,4], [4,2,2], [1,2,3], [2,3,6], [5,3,1]]
Output: [0, 2, 3, 6, 1, 5]
Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3. Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6. Shortest path from 0 to 4 is 0->4 with edge weight 1.Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.

// User function Template for C++
class Solution {
private:
void dfs(int node, vector<pair<int, int>> adj[], vector<int> &vis, stack<int> &st) {
        vis[node] = 1;  // Mark the current node as visited
        // Traverse all adjacent nodes
        for (auto it : adj[node]) {
            int v = it.first;  // Get the neighboring vertex
            // If the neighboring vertex is not visited, perform DFS on it
            if (!vis[v]) dfs(v, adj, vis, st);
        }
        st.push(node);  // Push the current node to stack after all its neighbors
    }
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        // Create adjacency list
        vector<pair<int, int>> adj[V];
        for (int i = 0; i < E; i++) {
            int u = edges[i][0];  // Starting node
            int v = edges[i][1];  // Ending node
            int wt = edges[i][2]; // Weight of the edge
            adj[u].push_back({v, wt}); // Add to the adjacency list
        }

        // Initialize visited array and stack for topological sorting
        vector<int> vis(V, 0);
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) dfs(i, adj, vis, st);  // Call DFS for unvisited nodes
        }

        // Initialize distances to "infinity"
        vector<int> dist(V, INT_MAX);
        dist[0] = 0;  // Distance to the source node (0) is 0

        // Process nodes in topological order
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            for (auto it : adj[node]) {
                int v = it.first;    // Target node
                int wt = it.second;  // Weight of the edge

                // Relax the edge if possible
                if (dist[node] != INT_MAX && dist[node] + wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }
        }

        // Replace "infinity" with -1 for unreachable nodes
        for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) dist[i] = -1;
        }

        return dist;  // Return the computed shortest paths
    }
};
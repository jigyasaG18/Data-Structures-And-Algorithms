Bridges in Graph
There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.
A critical connection is a connection that, if removed, will make some servers unable to reach some other server.
Return all critical connections in the network in any order.

Example 1:
Input: n = 4, connections = [[0,1],[1,2],[2,0],[1,3]]
Output: [[1,3]]
Explanation: [[3,1]] is also accepted.

Example 2:
Input: n = 2, connections = [[0,1]]
Output: [[0,1]]

class Solution {
private:
    int timer = 1;
    
    void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int tin[], int low[], vector<vector<int>> &bridges) {
        vis[node] = 1;
        low[node] = tin[node] = timer;
        timer++;
        
        for (auto it : adj[node]) {
            if (it == parent) continue; // Don't go back to the parent
            
            if (vis[it] == 0) {
                dfs(it, node, vis, adj, tin, low, bridges);
                
                // Check if the subtree rooted at it has a back connection
                low[node] = min(low[node], low[it]);
                
                // If the lowest reachable vertex from subtree under it is below node in DFS tree, then it's a bridge
                if (low[it] > tin[node]) {
                    bridges.push_back({node, it});
                }
            } else {
                // Update low value of node for parent function calls
                low[node] = min(low[node], tin[it]);
            }
        }
    }
    
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        
        // Build the adjacency list
        for (auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]); 
        }
        
        vector<int> vis(n, 0);
        vector<vector<int>> bridges;
        int tin[n];
        int low[n];
        
        // Start DFS from node 0 (or any node, as the input graph is connected)
        dfs(0, -1, vis, adj, tin, low, bridges);
        
        return bridges;
    }
};

2nd Way of Question:-
Given a Graph of V vertices and E edges and another edge(c - d), the task is to find if the given edge is a Bridge. i.e., removing the edge disconnects the graph.

Example 1:
Input: c = 1, d = 2
Output: 1
Explanation: From the graph, we can clearly see that blocking the edge 1-2 will result in  disconnection of the graph. So, it is a Bridge and thus the Output 1.

Example 2:
Input: c = 0, d = 2
Output: 0
Explanation: blocking the edge between nodes 0 and 2 won't affect the connectivity of the graph. So, it's not a Bridge Edge. All the Bridge
 
Your Task:
You don't need to read input or print anything. Your task is to complete the function isBridge()  which takes number of vertices V, the number of edges E, an adjacency lsit adj and two integers c and d denoting the edge as input parameters and returns 1 if the given edge c-d is a Bridge. Else, it returns 0.

class Solution
{
    private:
    int timer = 1;
    
    void dfs(int node, int parent, vector<int> &vis, vector<int> adj[], int tin[], int low[], vector<vector<int>> &bridges) {
        vis[node] = 1;
        low[node] = tin[node] = timer;
        timer++;
        
        for (auto it : adj[node]) {
            if (it == parent) continue; // Don't go back to the parent
            
            if (vis[it] == 0) {
                dfs(it, node, vis, adj, tin, low, bridges);
                
                // Check if the subtree rooted at it has a back connection
                low[node] = min(low[node], low[it]);
                
                // If the lowest reachable vertex from subtree under it is below node in DFS tree, then it's a bridge
                if (low[it] > tin[node]) {
                    bridges.push_back({node, it});
                }
            } else {
                // Update low value of node for parent function calls
                low[node] = min(low[node], tin[it]);
            }
        }
    }
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        vector<int> vis(V, 0);
        vector<vector<int>> bridges;
        int tin[V];
        int low[V];
        
          for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, vis, adj, tin, low, bridges);
            }
        }

          for (auto it : bridges) {
            if ((it[0] == c && it[1] == d) || (it[0] == d && it[1] == c)) {
                return true;
            }
        }
        
        return false;
    }
};
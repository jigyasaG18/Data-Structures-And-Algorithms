Eventual Safe States
A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.
A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.
You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.

Example 2:
Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
Output: [4]
Explanation:
Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.
 
1st Way:-
class Solution {
    private:
    bool dfs(int node, vector<int> adj[], int vis[], int pathvis[], int check[]) {
        vis[node] = 1; 
        pathvis[node] = 1;  // Mark node in the current path
        check[node] = 0; // Initialize to indicate not yet safe

        for (auto it : adj[node]) {
            // if the neighbor hasn't been visited yet
            if (!vis[it]) { 
                // Recur for the neighbor
                if (dfs(it, adj, vis, pathvis, check)==true) {
                    check[node] = 0;  // If a cycle is detected, it's not safe
                    return true; // Cycle found
                }
            } else if (pathvis[it]) { 
                // If we encountered a node in the current path
                check[node] = 0; 
                return true; // Cycle found
            }
        }

        // Mark node as safe since no cycles were found in its path
        check[node] = 1; 
        pathvis[node] = 0; // Backtrack
        return false; // No cycle detected
    }
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
         int vis[V] = {0}; // Visited array
        int pathvis[V] = {0}; // Path visitation array
        int check[V] = {0}; // Safe nodes check array
        vector<int> safenodes;

        // Perform DFS for each node
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, adj, vis, pathvis, check);
            }
        }

        // Collect the safe nodes
        for (int i = 0; i < V; i++) {
            if (check[i] == 1) {
                safenodes.push_back(i);
            }
        }

        // Sort safe nodes for ordered output
        sort(safenodes.begin(), safenodes.end());
        return safenodes;
    }
};

2nd Way:-
class Solution {
    private:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, vector<int>& pathvis, vector<int>& check) {
        vis[node] = 1; 
        pathvis[node] = 1;  // Mark node in the current path
        check[node] = 0; // By default, assume it is not safe

        for (auto it : graph[node]) {
            if (!vis[it]) { 
                if (dfs(it, graph, vis, pathvis, check)) {
                    check[node] = 0;  // If a cycle is detected, it's not safe
                    return true;
                }
            } else if (pathvis[it]) { 
                check[node] = 0; // Cycle detected through path
                return true;
            }
        }

        check[node] = 1; // Mark node as safe
        pathvis[node] = 0; // Backtrack
        return false; // No cycle detected
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> vis(V, 0); // Visited array
        vector<int> pathvis(V, 0); // Path visitation array
        vector<int> check(V, 0); // Safe nodes check array
        vector<int> safenodes;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, graph, vis, pathvis, check);
            }
        }
        
        for (int i = 0; i < V; i++) {
            if (check[i] == 1) {
                safenodes.push_back(i);
            }
        }
        
        // Sort safe nodes for ordered output, if required
        sort(safenodes.begin(), safenodes.end());
        return safenodes;
    }
};
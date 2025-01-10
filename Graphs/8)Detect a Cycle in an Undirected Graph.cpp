Detect a Cycle in an Undirected Graph
Given an undirected graph with V vertices labelled from 0 to V-1 and E edges, check whether the graph contains any cycle or not. The Graph is represented as an adjacency list, where adj[i] contains all the vertices that are directly connected to vertex i.
NOTE: The adjacency list represents undirected edges, meaning that if there is an edge between vertex i and vertex j, both j will be adj[i] and i will be in adj[j].

Examples:
Input: adj = [[1], [0,2,4], [1,3], [2,4], [1,3]] 
Output: 1
Explanation: 1->2->3->4->1 is a cycle.

Input: adj = [[], [2], [1,3], [2]]
Output: 0
Explanation: No cycle in the graph.

USING BFS:-
class Solution {
    private:
    bool detect(int src, vector<vector<int>> &adj, vector<int> &vis){
        vis[src]=1; // mark the source as visited
        queue<pair<int,int>>q;
        q.push({src,-1}); // push the source with parent as -1
        
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            
            for(auto adjacentnode: adj[node]){
                if(!vis[adjacentnode]){ // if it's not visited
                    vis[adjacentnode]=1; // mark as visited
                    q.push({adjacentnode,node}); // add to the queue with current node as parent
                }
                else if(parent!=adjacentnode){ // if visited and it's not the parent
                    return true; // cycle detected
                }
            }
        }
        return false; // no cycle was detected in this component
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size(); // number of nodes
        vector<int> vis(n,0); // initialize visited vector of size n
        for(int i=0;i<n;i++){
            if(!vis[i]){ // if the node is not visited
                if(detect(i,adj,vis)){ // if cycle is detected from this node
                    return true;
                }
            }
        }
        return false; // no cycle found in any component
    }
};

USING DFS:-
class Solution {
    private:
   // Helper function to perform DFS traversal and detect cycles
    bool detect(int src, int parent, vector<vector<int>>& adj, vector<int>& vis) {
        vis[src] = 1; // Mark the source node as visited

        for (auto adjacentNode : adj[src]) {
            // If the adjacent node is not visited, recursively call detect
            if (!vis[adjacentNode]) {
                if (detect(adjacentNode, src, adj, vis)) {
                    return true; // Cycle detected in the recursive call
                }
            }
            // If the adjacent node is visited and is not the parent of the current node
            else if (parent != adjacentNode) {
                return true; // Cycle detected
            }
        }
        return false; // No cycle detected in this component
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
         int n = adj.size(); // Number of nodes in the graph
        vector<int> vis(n, 0); // Visited vector to keep track of visited nodes
        
        // Check each component of the graph
        for (int i = 0; i < n; i++) {
            if (!vis[i]) { // If the node is not visited
                if (detect(i, -1, adj, vis)) {
                    return true; // If a cycle is detected, return true
                }
            }
        }
        return false; // No cycle was found in any component
    }
};
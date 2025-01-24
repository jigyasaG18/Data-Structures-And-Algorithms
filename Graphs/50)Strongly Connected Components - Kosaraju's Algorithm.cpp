Strongly Connected Components - Kosaraju's Algorithm
Given an adjacency list, adj of Directed Graph, Find the number of strongly connected components in the graph.

Examples :
Input: adj[][] = [[2, 3], [0], [1], [4], []]
Output: 3
Explanation: We can clearly see that there are 3 Strongly Connected Components in the Graph.
 
Input: adj[][] = [[1], [2], [0]]
Output: 1
Explanation: All of the nodes are connected to each other. So, there's only one SCC.

Input: adj[][] = [[1], []]
Output: 2

class Solution {
    private:
    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st){
        vis[node] = 1;
        for(auto it : adj[node]){
            if(!vis[it]) dfs(it, vis, adj, st);
        }
        st.push(node);
    }

    void dfs3(int node, vector<int> &vis, vector<vector<int>> &adjT){
        vis[node] = 1;
        for(auto it : adjT[node]){
            if(!vis[it]) dfs3(it, vis, adjT);
        }
    }
  public:
    int kosaraju(vector<vector<int>> &adj) {
        // code here
         int V = adj.size();
        vector<int>vis(V, 0);
        stack<int>st;

        for(int i = 0; i < V; i++){
            if(!vis[i]) dfs(i, vis, adj, st);
        }

        // Create transpose graph
        vector<vector<int>> adjT(V);
        for(int i = 0; i < V; i++){
            vis[i] = 0;
            for(auto it : adj[i]){
                adjT[it].push_back(i); // Changed adj to adjT
            }
        }

        int scc = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]) {
                scc++;
                dfs3(node, vis, adjT);
            }
        }
        return scc;
    }
};
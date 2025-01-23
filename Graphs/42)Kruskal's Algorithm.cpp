Kruskal's Algorithm
Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is represented by an adjacency list, where each element adj[i] is a vector containing vector of integers. Each vector represents an edge, with the first integer denoting the endpoint of the edge and the second integer denoting the weight of the edge.

class DisjointSet {
      vector<int> parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        vector<pair<int, pair<int, int>>> edges;
        for(int i=0;i<V;i++){
            for(auto it : adj[i]){
            int adjnode=it[0];
            int wt=it[1];
            int node=i;
            
            edges.push_back({wt, {node, adjnode}});
        }}
        sort(edges.begin(),edges.end());
        int mstwt=0;
        DisjointSet ds(V);
        for(auto it : edges){
            int weight=it.first;
            int u=it.second.first;
            int v=it.second.second;
    if(ds.findUPar(u) != ds.findUPar(v)){
        mstwt+=weight;
        ds.unionBySize(u,v);
    }
        }
        return mstwt;
    }
};
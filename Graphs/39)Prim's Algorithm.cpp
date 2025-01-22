Prim's Algorithm
Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. The graph is represented by an adjacency list, where each element adj[i] is a vector containing vector of integers. Each vector represents an edge, with the first integer denoting the endpoint of the edge and the second integer denoting the weight of the edge.

class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
      vector<int>vis(V,0);
      int sum=0;
      pq.push({0,0}); //{weight,node}
      while(!pq.empty()){
          auto it = pq.top();
          pq.pop();
          int node=it.second;
          int weight=it.first;
          
          if(vis[node]==1) continue; //already visited 
          vis[node]=1;
          sum+=weight;
          
          for(auto it : adj[node]){
              int adjnode=it[0];
              int edgeweight=it[1];
            if(!vis[adjnode]) {pq.push({edgeweight,adjnode});}
          }
      }
      return sum;
    }
};
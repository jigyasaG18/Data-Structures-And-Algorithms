Shortest Path in Weighted Undirected Graph
You are given a weighted undirected graph having n vertices numbered from 1 to n and m edges along with their weights. Find the shortest weight path between the vertex 1 and the vertex n,  if there exists a path, and return a list of integers whose first element is the weight of the path, and the rest consist of the nodes on that path. If no path exists, then return a list containing a single element -1.
The input list of edges is as follows - {a, b, w}, denoting there is an edge between a and b, and w is the weight of that edge.
Note: The driver code here will first check if the weight of the path returned is equal to the sum of the weights along the nodes on that path, if equal it will output the weight of the path, else -2. In case the list contains only a single element (-1) it will simply output -1. 

Examples :
Input: n = 5, m= 6, edges = [[1, 2, 2], [2, 5, 5], [2, 3, 4], [1, 4, 1], [4, 3, 3], [3, 5, 1]]
Output: 5
Explanation: Shortest path from 1 to n is by the path 1 4 3 5 whose weight is 5. 

Input: n = 2, m= 1, edges = [[1, 2, 2]]
Output: 2
Explanation: Shortest path from 1 to 2 is by the path 1 2 whose weight is 2. 

Input: n = 2, m= 0, edges = [ ]
Output: -1
Explanation: Since there are no edges, so no answer is possible.

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<int>dist(n+1,INT_MAX);
        vector<int>parent(n+1,0);
        dist[1]=0;
        for(int i=1;i<=n;i++) parent[i]=i;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,1});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int distance = it.first;
            int node = it.second;
            
            for(auto it : adj[node]){
                int adjnode = it.first;
                int weight = it.second;
                
    if(distance + weight < dist[adjnode]){
        dist[adjnode] = distance + weight;
        parent[adjnode] = node;
        pq.push({dist[adjnode],adjnode});
    }
            }
        }
        if(dist[n]==INT_MAX) return {-1};
        vector<int>res;
        int node=n;
        while(parent[node] != node){
            res.push_back(node);
            node=parent[node];
        }
        res.push_back(1);
        res.push_back(dist[n]);
        reverse(res.begin(),res.end());
        return res;
    }
};
Djisktra's Algorithm
Given a weighted, undirected and connected graph where you have given adjacency list adj. You have to find the shortest distance of all the vertices from the source vertex src, and return a list of integers denoting the shortest distance between each node and source vertex src.
Note: The Graph doesn't contain any negative weight edge.

Examples:
Input: adj = [[[1, 9]], [[0, 9]]], src = 0
Output: [0, 9]
Explanation: The source vertex is 0. Hence, the shortest distance of node 0 is 0 and the shortest distance from node 0 to 1 is 9.

Input: adj = [[[1, 1], [2, 6]], [[2, 3], [0, 1]], [[1, 3], [0, 6]]], src = 2
Output: [4, 3, 0]
Explanation: For nodes 2 to 0, we can follow the path 2-1-0. This has a distance of 1+3 = 4, whereas the path 2-0 has a distance of 6. So, the Shortest path from 2 to 0 is 4.
The shortest distance from 0 to 1 is 1 .

1st Way:- USING PRIORITY QUEUE
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        int V = adj.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(V, INT_MAX);
    
    dist[src] = 0; // Distance to the source is 0
    pq.push({0, src}); // Push the source node into the priority queue

    while (!pq.empty()) {
        int distance = pq.top().first; // Current distance
        int node = pq.top().second; // Current node
        pq.pop();

        // Explore all adjacent nodes
        for (auto it : adj[node]) {
            int adjnode = it.first; // Get the adjacent node
            int edgeweight = it.second; // Get the edge weight
            
            // If a shorter path to adjnode is found
            if (distance + edgeweight < dist[adjnode]) {
                dist[adjnode] = distance + edgeweight; // Update the distance to the adjacent node
                pq.push({dist[adjnode], adjnode}); // Push updated distance and node to the priority queue
            }
        }
    }
    return dist; // Return the array of distances
    }
};

2nd Way:- USING SET
// User Function Template
class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        int V=adj.size();
        set<pair<int,int>>st;
        vector<int>dist(V,INT_MAX);
        st.insert({0,src});
        dist[src]=0;
        while(!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            int distance = it.first;
            st.erase(it);
            
            for(auto it : adj[node]){
                int adjnode=it.first;
                int weight=it.second;
                
    if(distance + weight < dist[adjnode]){
        if(dist[adjnode]!=INT_MAX){
            st.erase({dist[adjnode],adjnode});
        }
        
        dist[adjnode]=distance+weight;
        st.insert({dist[adjnode],adjnode});
    }
            }
        }
        return dist;
    }
};
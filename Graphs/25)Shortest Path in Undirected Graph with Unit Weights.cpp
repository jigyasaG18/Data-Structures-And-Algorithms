Shortest Path in Undirected Graph with Unit Weights
You are given an adjacency list, adj of Undirected Graph having unit weight of the edges, find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, then return -1 for that vertex.

Examples :
Input: adj[][] = [[1, 3], [0, 2], [1, 6], [0, 4], [3, 5], [4, 6], [2, 5, 7, 8], [6, 8], [7, 6]], src=0
Output: [0, 1, 2, 1, 2, 3, 3, 4, 4]

Input: adj[][]= [[3], [3], [], [0, 1]], src=3
Output: [1, 1, -1, 0]

Input: adj[][]= [[], [], [], [4], [3], [], []], src=1
Output: [-1, 0, -1, -1, -1, -1, -1] 

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
          int n = adj.size();
    vector<int> dist(n, -1); // Initialize distances with -1
    queue<int> q;

    // Start BFS from the source node
    q.push(src);
    dist[src] = 0; // Distance to the source is 0

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // Traverse all adjacent nodes
        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) { // If neighbor has not been visited
                dist[neighbor] = dist[node] + 1; // Update distance
                q.push(neighbor); // Add neighbor to the queue
            }
        }
    }

    return dist; // Return the distance array
    }
};
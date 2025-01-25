Network Delay Time
You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.
We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

Example 1:
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

Example 2:
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1

Example 3:
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto it: times){
            adj[it[0]].push_back({it[1],it[2]});
        }

        vector<int> dist(n+1,INT_MAX);
        dist[k]=0;
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});   //{time,node}
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int time=it.first;
            int node=it.second;

            for(auto it: adj[node]){
                int adjNode=it.first;
                int t=it.second;

                if(time+t < dist[adjNode]){
                    dist[adjNode]=time+t;
                    pq.push({time+t,adjNode});
                }
            }
        }

        int maxTime=INT_MIN;
        for(int i=1;i<=n;i++){
            if(dist[i] == INT_MAX) return -1;
            maxTime=max(maxTime,dist[i]);
        }
        return maxTime;
    }
};
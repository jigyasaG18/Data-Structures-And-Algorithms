Course Schedule or Prerequisite Tasks
There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
Given the total number of tasks N and a list of P prerequisite pairs, find if it is possible to finish all tasks.

Examples:
Input: N = 4, P = 3, prerequisites = [[1,0],[2,1],[3,2]]
Output: Yes
Explanation: To do task 1 you should have completed task 0, and to do task 2 you should have finished task 1, and to do task 3 you should have finished task 2. So it is possible.

Input: N = 2, P = 2, prerequisites = [[1,0],[0,1]]
Output: No
Explanation: To do task 1 you should have completed task 0, and to do task 0 you should have finished task 1. So it is impossible.

1st Way:-
class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        // Code here
        vector<int>adj[N];
        for(auto it : prerequisites){
            adj[it.first].push_back(it.second);
        }
        int indegree[N]={0};
        for(int i=0;i<N;i++){
            for(auto it : adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<N;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        vector<int>ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            
            for(auto it : adj[node]){
                indegree[it]--;
                
                if(indegree[it]==0) q.push(it);
            }
        }
        
        if(ans.size()==N) return true;
        return false;
    }
};

2nd Way:-
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
         vector<int> adj[numCourses];
        // Correctly build the adjacency list from prerequisites
        for (auto it : prerequisites) {
            adj[it[1]].push_back(it[0]);  // The prerequisite is it[1] and the course dependent on it is it[0]
        }
        
        vector<int> indegree(numCourses, 0);
        // Calculate the indegree of each course
        for (int i = 0; i < numCourses; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
        
        queue<int> q;
        // Push all courses with indegree of 0 into the queue
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) q.push(i);
        }
        
        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            
            for (auto it : adj[node]) {
                indegree[it]--;
                
                if (indegree[it] == 0) q.push(it);
            }
        }
        
        // If we were able to take all courses
        if(ans.size() == numCourses) return true;
        return false;
    }
};
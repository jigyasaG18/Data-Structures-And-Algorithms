Job Sequencing Problem
You are given two arrays: deadline[], and profit[], which represent a set of jobs, where each job is associated with a deadline, and a profit. Each job takes 1 unit of time to complete, and only one job can be scheduled at a time. You will earn the profit associated with a job only if it is completed by its deadline.
Your task is to find:
The maximum number of jobs that can be completed within their deadlines.
The total maximum profit earned by completing those jobs.

Examples :
Input: deadline[] = [4, 1, 1, 1], profit[] = [20, 10, 40, 30]
Output: [2, 60]
Explanation: Job1 and Job3 can be done with maximum profit of 60 (20+40).

Input: deadline[] = [2, 1, 2, 1, 1], profit[] = [100, 19, 27, 25, 15]
Output: [2, 127]
Explanation: Job1 and Job3 can be done with maximum profit of 127 (100+27).

Input: deadline[] = [3, 1, 2, 2], profit[] = [50, 10, 20, 30]
Output: [3, 100]
Explanation: Job1, Job3 and Job4 can be completed with a maximum profit of 100 (50 + 20 + 30).

Brute Force:-
class Solution {
    public:
      vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
          // code here
          int n=deadline.size();
          int cnt=0;
          int tprofit=0;
          vector<pair<int,int>>jobs;
          for(int i=0;i<n;i++){
              jobs.push_back({profit[i],deadline[i]});
          }
          // sort the jobs based on profit in decreasing order
          sort(jobs.begin(),jobs.end(),greater<pair<int,int>>());
           vector<int> slot(n, 0);
      for (int i = 0; i < n; i++) {
          int start = min(n, jobs[i].second) - 1;
          for (int j = start; j >= 0; j--) {
  
              // if slot is empty
              if (slot[j] == 0) {
                  slot[j] = 1;
                  cnt++;
                  tprofit+= jobs[i].first;
                  break;
              }
          }
      }
      
      return {cnt, tprofit};
      }
  };

Optimal Approach:-
class Solution {
    public:
      vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
          // code here
             int n = deadline.size();
      vector<int> ans = {0, 0};
  
      // pair the profit and deadline of
      // all the jos together
      vector<pair<int, int>> jobs;
      for (int i = 0; i < n; i++) {
          jobs.push_back({deadline[i], profit[i]});
      }
  
      // sort the jobs based on deadline
      // in ascending order
      sort(jobs.begin(), jobs.end());
  
      // to maintain the scheduled jobs based on profit
      priority_queue<int, vector<int>, greater<int>> pq;
  
      for (const auto &job : jobs) {
          
          // if job can be scheduled within its deadline
          if (job.first > pq.size())
              pq.push(job.second);
          
          // Replace the job with the lowest profit
          else if (!pq.empty() && pq.top() < job.second) {
              pq.pop();
              pq.push(job.second);
          }
      }
  
      while (!pq.empty()) {
          ans[1] += pq.top();
          pq.pop();
          ans[0]++;
      }
  
      return ans;
      }
  };
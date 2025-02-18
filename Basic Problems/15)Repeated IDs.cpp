Repeated IDs
Geek is given a task to select at most 10 employees for a company project. Each employee is represented by a single-digit ID number which is unique for all the selected employees for the project. Geek has a technical problem in his system which printed ID number multiple times. You are given array arr having all printed IDs. Help him to get rid of the repeated IDs.

Examples:
Input: arr[] = [8, 8, 6, 2, 1] 
Output: [8, 6, 2, 1] 
Explanation: 8 is repeated, so takes 8 single time.

Input: arr[] = [7, 6, 7, 4, 2, 7] 
Output: [7, 6, 4, 2] 
Explanation: 7 and 6 are repeated, so take 7 and 6 single time.

1st Way:-
class Solution {
    public:
      vector<int> uniqueId(vector<int>& arr) {
          // code
          int n=arr.size();
          unordered_map<int,int>mpp;
          vector<int>ans;
          for(auto it : arr){
              mpp[it]++;
          }
          for (int x : arr) {
          if (mpp[x] > 0) {
              ans.push_back(x);
              mpp[x] = 0; // Mark as visited to avoid duplicates
          }
      }
          return ans;
      }
  };

2nd Way:-
class Solution {
    public:
      vector<int> uniqueId(vector<int>& arr) {
          // code
          int n=arr.size();
          unordered_map<int,int>mpp;
          vector<int>ans;
          for(auto it : arr){
              mpp[it]++;
          }
          for (int i = 0; i < n; i++) {
          if (mpp[arr[i]] > 0) {
              ans.push_back(arr[i]);
              mpp[arr[i]] = 0; // Mark as visited
          }
      }
          return ans;
      }
  };
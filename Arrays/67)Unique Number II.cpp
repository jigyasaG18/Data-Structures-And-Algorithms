Unique Number II
Given an array arr[] containing 2*n + 2 positive numbers, out of which 2*n numbers exist in pairs whereas only two number occur exactly once and are distinct. Find the other two numbers. Return the answer in increasing order.

Examples:
Input: arr[] = [1, 2, 3, 2, 1, 4]
Output: [3, 4] 
Explanation: 3 and 4 occur exactly once.

Input: arr[] = [2, 1, 3, 2]
Output: [1, 3]
Explanation: 1 and 3 occur exactly once.

Input: arr[] = [2, 1, 3, 3]
Output: [1, 2]
Explanation: 1 and 2 occur exactly once.

class Solution {
    public:
      vector<int> singleNum(vector<int>& arr) {
          // Code here.
          unordered_map<int,int>mpp;
          vector<int>ans;
          for(auto it :arr){
              mpp[it]++;
          }
          for(auto it :mpp){
              if(it.second==1) ans.push_back(it.first);
          }
          sort(ans.begin(),ans.end());
          return ans;
      }
  };
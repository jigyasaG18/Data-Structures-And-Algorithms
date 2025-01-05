Two sum -Pairs with 0 Sum
Given an integer array arr, return all the unique pairs [arr[i], arr[j]] such that i != j and arr[i] + arr[j] == 0.
Note: The pairs must be returned in sorted order, the solution array should also be sorted, and the answer must not contain any duplicate pairs.

Examples:
Input: arr = [-1, 0, 1, 2, -1, -4]
Output: [[-1, 1]]
Explanation: arr[0] + arr[2] = (-1)+ 1 = 0.
arr[2] + arr[4] = 1 + (-1) = 0.
The distinct pair are [-1,1].

Input: arr = [6, 1, 8, 0, 4, -9, -1, -10, -6, -5]
Output: [[-6, 6],[-1, 1]]
Explanation: The distinct pairs are [-1, 1] and [-6, 6].

class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        // code here
        sort(arr.begin(),arr.end());
        vector<vector<int>>ans;
        int n=arr.size();
        int i=0;
        int j=n-1;
        while(i<j){
            int sum=arr[i]+arr[j];
            if(sum==0) 
            {
            ans.push_back({arr[i],arr[j]});
                
            // Skip duplicates for arr[i]
            while (i < j && arr[i] == arr[i + 1]) i++;
            // Skip duplicates for arr[j]
            while (i < j && arr[j] == arr[j - 1]) j--;
            
                i++;
                j--;
            }
            else if(sum<0) i++;
            else j--;  //sum>0
            
        }
        return ans;
    }
};
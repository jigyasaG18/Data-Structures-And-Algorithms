Pascal Triangle
Given a positive integer n, return the nth row of pascal's triangle.
Pascal's triangle is a triangular array of the binomial coefficients formed by summing up the elements of previous row.

Examples:
Input: n = 4
Output: [1, 3, 3, 1]
Explanation: 4th row of pascal's triangle is [1, 3, 3, 1].

Input: n = 5
Output: [1, 4, 6, 4, 1]
Explanation: 5th row of pascal's triangle is [1, 4, 6, 4, 1].

Input: n = 1
Output: [1]
Explanation: 1st row of pascal's triangle is [1].

class Solution {
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
         vector<vector<int>>ans;
        for(int i=0; i<n; i++){
            vector<int>v(i+1,1);
            for(int j=1; j<i;j++){
                v[j]=ans[i-1][j]+ans[i-1][j-1];
            }
            ans.push_back(v);
        }
        return ans[n-1];
    }
};
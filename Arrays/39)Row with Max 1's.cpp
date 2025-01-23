Row with Max 1's
You are given a 2D binary array arr[][] consisting of only 1s and 0s. Each row of the array is sorted in non-decreasing order. Your task is to find and return the index of the first row that contains the maximum number of 1s. If no such row exists, return -1.

Note:
The array follows 0-based indexing.
The number of rows and columns in the array are denoted by n and m respectively.

Examples:
Input: arr[][] = [[0,1,1,1], [0,0,1,1], [1,1,1,1], [0,0,0,0]]
Output: 2
Explanation: Row 2 contains the most number of 1s (4 1s). Hence, the output is 2.

Input: arr[][] = [[0,0], [1,1]]
Output: 1
Explanation: Row 1 contains the most number of 1s (2 1s). Hence, the output is 1.

Input: arr[][] = [[0,0], [0,0]]
Output: -1
Explanation: No row contains any 1s, so the output is -1.

// User function template for C++
class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        int n=arr.size();
        int m=arr[0].size();
        int maxi=0;
        int ans=-1; //its a 0 based indexing so if we take ans=0 means we are starting from 0th row hence resulting in incorrect answer
        for(int i=0;i<n;i++){
            int cnt=0; //because after every column iteration it gets 0 again so that answer is correct
            for(int j=0;j<m;j++){
                if(arr[i][j] == 1) cnt++;
            }
            if(cnt > maxi){
                maxi=cnt;
                ans=i;
            }
        }
        return ans;
    }
};
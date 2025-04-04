Minimum Cost Tree From Leaf Values
Given an array arr of positive integers, consider all binary trees such that:
Each node has either 0 or 2 children;
The values of arr correspond to the values of each leaf in an in-order traversal of the tree.
The value of each non-leaf node is equal to the product of the largest leaf value in its left and right subtree, respectively.
Among all possible binary trees considered, return the smallest possible sum of the values of each non-leaf node. It is guaranteed this sum fits into a 32-bit integer.
A node is a leaf if and only if it has zero children.

Example 1:
Input: arr = [6,2,4]
Output: 32
Explanation: The first has a non-leaf node sum 36, and the second has non-leaf node sum 32.

Example 2:
Input: arr = [4,11]
Output: 44

class Solution {
    public:
    int solve(vector<int>&arr,map<pair<int,int>,int>&mpp,vector<vector<int>>&dp,int left,int right){
        if(left==right) return 0; //leaf node
        if(dp[left][right]!=-1) return dp[left][right];
        int ans=INT_MAX;
        for(int i=left;i<right;i++){
            ans=min(ans,mpp[{left,i}]*mpp[{i+1,right}]+solve(arr,mpp,dp,left,i)+solve(arr,mpp,dp,i+1,right));
        }
        return dp[left][right]=ans;
    }
        int mctFromLeafValues(vector<int>& arr) {
            int n=arr.size();
            map<pair<int,int>,int>mpp;
            vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
            for(int i=0;i<n;i++){
                mpp[{i,i}]=arr[i];
                for(int j=i+1;j<n;j++){
                    mpp[{i,j}]=max(arr[j],mpp[{i,j-1}]);
                }
            }
            return solve(arr,mpp,dp,0,n-1);
        }
    };
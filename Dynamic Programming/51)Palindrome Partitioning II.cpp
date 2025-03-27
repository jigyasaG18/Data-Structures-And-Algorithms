Palindrome Partitioning II
Given a string s, partition s such that every substring of the partition is a palindrome.
Return the minimum cuts needed for a palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: 1
Explanation: The palindrome partitioning ["aa","b"] could be produced using 1 cut.

Example 2:
Input: s = "a"
Output: 0

Example 3:
Input: s = "ab"
Output: 1

1st Way:- MEMOIZATION
class Solution {
    public:
    bool ispalindrome(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int func(int i,int n,string s,vector<int>&dp){
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int mincost=INT_MAX;
        for(int j=i;j<n;j++){
            if(ispalindrome(i,j,s)) {
            int cost=1+func(j+1,n,s,dp);
            mincost=min(mincost,cost);
            }
        }
        return dp[i]=mincost;
    }
        int minCut(string s) {
            int n=s.size();
            vector<int>dp(n,-1);
            return func(0,n,s,dp)-1;
        }
    };

2nd Way:- TABULATION
class Solution {
    public:
    bool ispalindrome(int i,int j,string &s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
        int minCut(string s) {
            int n=s.size();
            vector<int>dp(n+1,0);
            dp[n]=0;
            for(int i=n-1;i>=0;i--){
                int mincost=INT_MAX;
        for(int j=i;j<n;j++){
            if(ispalindrome(i,j,s)) {
            int cost=1+dp[j+1];
            mincost=min(mincost,cost);
            }
        }
        dp[i]=mincost;
            }
            return dp[0]-1;
        }
    };
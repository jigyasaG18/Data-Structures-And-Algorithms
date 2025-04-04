Minimum Insertions/Deletions to Convert String 
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.
In one step, you can delete exactly one character in either string.

Example 1:
Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

Example 2:
Input: word1 = "leetcode", word2 = "etco"
Output: 4

class Solution {
    public:
    int longestCommonSubsequence(string text1, string text2) {
            int n=text1.size();
            int m=text2.size();
            vector<vector<int>>dp(n+1,vector<int>(m+1,0));
            for(int i=0;i<=n;i++) dp[i][0]=0;
            for(int j=0;j<=m;j++) dp[0][j]=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(text1[i-1]==text2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                    else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
            return dp[n][m];
    }
        int minDistance(string word1, string word2) {
            return (word1.size()+word2.size()-2*longestCommonSubsequence(word1,word2));
        }
    };
Minimum Insertion Steps to Make a String Palindrome
Given a string s. In one step you can insert any character at any index of the string.
Return the minimum number of steps to make s palindrome.
A Palindrome String is one that reads the same backward as well as forward.

Example 1:
Input: s = "zzazz"
Output: 0
Explanation: The string "zzazz" is already palindrome we do not need any insertions.

Example 2:
Input: s = "mbadm"
Output: 2
Explanation: String can be "mbdadbm" or "mdbabdm".

Example 3:
Input: s = "leetcode"
Output: 5
Explanation: Inserting 5 characters the string becomes "leetcodocteel".

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
        int longestPalindromeSubseq(string s) {
            string t=s;
            reverse(t.begin(),t.end());
            return longestCommonSubsequence(s,t);
        }
        int minInsertions(string s) {
            return s.size()-longestPalindromeSubseq(s);
        }
    };
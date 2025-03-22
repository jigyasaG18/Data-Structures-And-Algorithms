Edit Distance
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
You have the following three operations permitted on a word:
Insert a character
Delete a character
Replace a character
 
Example 1:
Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:
Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')

1st Way:- MEMOIZATION
class Solution {
    public:
    int func(int i,int j,string s1,string s2,vector<vector<int>>&dp){
    if(i<0) return j+1;
    if(j<0) return i+1;
    if(dp[i][j]!=-1) return dp[i][j];
    if(s1[i]==s2[j]){
        return dp[i][j]=0+func(i-1,j-1,s1,s2,dp);
    }
    int insert=1+func(i,j-1,s1,s2,dp);
    int delete_operation=1+func(i-1,j,s1,s2,dp);
    int replace=1+func(i-1,j-1,s1,s2,dp);
    return dp[i][j]=min({insert,delete_operation,replace});
    }
        int minDistance(string word1, string word2) {
            int n=word1.size();
            int m=word2.size();
            vector<vector<int>>dp(n,vector<int>(m,-1));
            return func(n-1,m-1,word1,word2,dp);
        }
    };

2nd Way:- TABULATION
class Solution {
    public:
        int minDistance(string word1, string word2) {
            int n=word1.size();
            int m=word2.size();
            vector<vector<int>>dp(n+1,vector<int>(m+1,0));
            for(int i=0;i<=n;i++) dp[i][0]=i;
            for(int j=0;j<=m;j++) dp[0][j]=j;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(word1[i-1]==word2[j-1]){
                        dp[i][j]=0+dp[i-1][j-1];
                    }
                    else{
                        dp[i][j]=1+min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]));
                    }
                }
            }
            return dp[n][m];
        }
    };

3rd Way:- SPACE OPTIMISATION
class Solution {
    public:
        int minDistance(string word1, string word2) {
            int n=word1.size();
            int m=word2.size();
            vector<int>prev(m+1,0);
            vector<int>curr(m+1,0);
            for(int j=0;j<=m;j++) prev[j]=j;
            for(int i=1;i<=n;i++){
                curr[0]=i;
                for(int j=1;j<=m;j++){
                    if(word1[i-1]==word2[j-1]){
                        curr[j]=0+prev[j-1];
                    }
                    else{
                        curr[j]=1+min(prev[j-1],min(prev[j],curr[j-1]));
                    }
                }
                prev=curr;
            }
            return prev[m];
        }
    };
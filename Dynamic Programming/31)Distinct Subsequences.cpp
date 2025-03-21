Distinct Subsequences
Given two strings s and t, return the number of distinct subsequences of s which equals t.
The test cases are generated so that the answer fits on a 32-bit signed integer.

Example 1:
Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation: As shown below, there are 3 ways you can generate "rabbit" from s.
rabbbit
rabbbit
rabbbit

Example 2:
Input: s = "babgbag", t = "bag"
Output: 5
Explanation: As shown below, there are 5 ways you can generate "bag" from s.
babgbag
babgbag
babgbag
babgbag
babgbag

1st Way:- MEMOIZATION
class Solution {
    public:
    int func(int i, int j, const string s, string t, vector<vector<int>>& dp) {
            if (j < 0) return 1; //All characters of t matched
        if (i < 0) return 0; //No characters left in s but t is not completely matched
            
            if (dp[i][j] != -1) return dp[i][j]; // Return the cached result
            
            if (s[i] == t[j]) {
                // Either use this character in s or ignore it
            return dp[i][j] = func(i - 1, j - 1, s, t, dp) + func(i - 1, j, s, t, dp);
            } else {
                // Ignore this character from s
                return dp[i][j] = func(i - 1, j, s, t, dp);
            }
        }
        int numDistinct(string s, string t) {
            int n=s.size();
            int m=t.size();
            vector<vector<int>>dp(n,vector<int>(m,-1));
            return func(n-1,m-1,s,t,dp);
        }
    };

2nd Way:- TABULATION
class Solution {
    public:
        int numDistinct(string s, string t) {
            int n=s.size();
            int m=t.size();
            vector<vector<double>>dp(n+1,vector<double>(m+1,0));
            for(int i=0;i<=n;i++) dp[i][0]=1;
            for(int j=1;j<=m;j++) dp[0][j]=0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(s[i-1]==t[j-1]){
                        dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                    }
                    else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
            }
            return dp[n][m];
        }
    };

3rd Way:- SPACE OPTIMISATION
class Solution {
    public:
        int numDistinct(string s, string t) {
            int n=s.size();
            int m=t.size();
            vector<double>prev(m+1,0);
            vector<double>curr(m+1,0);
           prev[0]=curr[0]=1;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(s[i-1]==t[j-1]){
                        curr[j]=prev[j-1]+prev[j];
                    }
                    else{
                        curr[j]=prev[j];
                    }
                }
                prev=curr;
            }
            return curr[m];
        }
    };

4th Way:- 1-D Array SPACE OPTIMISATION
class Solution {
    public:
        int numDistinct(string s, string t) {
            int n=s.size();
            int m=t.size();
            vector<double>prev(m+1,0);
           prev[0]=1;
            for(int i=1;i<=n;i++){
                for(int j=m;j>=1;j--){
                    if(s[i-1]==t[j-1]){
                        prev[j]=prev[j-1]+prev[j];
                    }
                    // else{     this can be omitted also
                    //     prev[j]=prev[j];
                    // }
                }
            }
            return prev[m];
        }
    };
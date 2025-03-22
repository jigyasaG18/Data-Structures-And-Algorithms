Wildcard Matching
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:
'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

Example 1:
Input: s = "aa", p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "*"
Output: true
Explanation: '*' matches any sequence.

Example 3:
Input: s = "cb", p = "?a"
Output: false
Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.

1st Way:- MEMOIZATION
class Solution {
public:
    int func(int i, int j, string &s1, string &s2, vector<vector<int>>& dp) {
        // If we have exhausted both the string and the pattern
        if (i < 0 && j < 0) return true;
        // If we have exhausted the string but still have pattern left
        if (i >= 0 && j<0) return false;
        // If we have exhausted the pattern but still have string left
        if (i < 0 && j >= 0) {
            // Check if the remaining pattern can be matched with '*' only
            for (int a = 0; a <= j; a++) {
                if (s2[a] != '*') {
                    return false;
                }
            }
            return true;
        }
        // If we already computed this state, return the result
        if (dp[i][j] != -1) return dp[i][j];

        // Check if characters match or if there is a '?'
        if (s1[i] == s2[j] || s2[j] == '?') {
            return dp[i][j] = func(i - 1, j - 1, s1, s2, dp);
        }
        // If current character in pattern s2 is '*'
        if (s2[j] == '*') {
            // Two possibilities:
            // 1. '*' matches no character in s1
            // 2. '*' matches one more character in s1
            return dp[i][j] = func(i, j - 1, s1, s2, dp) || func(i - 1, j, s1, s2, dp);
        }

        // If characters do not match
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));  // Change to (n + 1) and (m + 1)
        return func(n - 1, m - 1, s, p, dp);
    }
};

2nd Way:- TABULATION
class Solution {
    public:
        bool isMatch(string s, string p) {
            int n = s.size();
            int m = p.size();
            vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    
            // Base case: empty pattern matches empty string
            dp[0][0] = true;
    
            // Handle patterns with '*' that can match an empty string
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == '*') {
                    dp[0][j] = dp[0][j - 1];
                }
            }
    
            // Fill the dp table
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    // Check for direct character match or '?'
                    if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                        dp[i][j] = dp[i - 1][j - 1];
                    }
                    // Handle '*' wildcard
                    else if (p[j - 1] == '*') {
                        dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                    }
                    // No match
                    else {
                        dp[i][j] = false;
                    }
                }
            }
    
            return dp[n][m];
        }
    };

3rd Way:- SPACE OPTIMISATION
class Solution {
    public:
        bool isMatch(string s, string p) {
            int n = s.size();
            int m = p.size();
            
            // Create a DP table for one dimension
            vector<bool> prev(m + 1, false);
            vector<bool> curr(m + 1, false);
            
            // Base case: empty pattern matches empty string
            prev[0] = true;
    
            // Handle patterns with '*' that can match an empty string
            for (int j = 1; j <= m; j++) {
                if (p[j - 1] == '*') {
                    prev[j] = prev[j - 1]; // '*' can match empty
                }
            }
    
            // Fill the DP table
            for (int i = 1; i <= n; i++) {
                curr[0] = false; // Non-empty string cannot match an empty pattern
    
                for (int j = 1; j <= m; j++) {
                    // Check for direct character match or '?'
                    if (s[i - 1] == p[j - 1] || p[j - 1] == '?') {
                        curr[j] = prev[j - 1]; // Match the current characters
                    } 
                    // Handle '*' wildcard
                    else if (p[j - 1] == '*') {
                        curr[j] = curr[j - 1] || prev[j]; // '*' matches either nothing or one more character
                    } 
                    // No match scenario
                    else {
                        curr[j] = false;
                    }
                }
                // Move to the next string character, so we copy current row to previous row
                prev=curr;
            }
    
            // Result is in the last cell after processing all characters of s
            return prev[m];
        }
    };

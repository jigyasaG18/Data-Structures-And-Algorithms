Word Break
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.

Example 3:
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false

class Solution {
    public:
        bool wordBreak(string s, vector<string>& wordDict) {
             int n=s.size();
            vector<bool>dp(n+1,false);
            dp[0]=true;
            set < string > st(wordDict.begin(), wordDict.end());
            // Find the maximum length of a word in the dictionary to limit the inner loop
        int maxLength = 0;
        for (const string &word : wordDict) {
            maxLength = max(maxLength, (int)word.length());
        }
           for (int i = 1; i <= n; i++) {
        for (int j = max(0,i-maxLength); j < i; j++) {
          if (dp[j] && st.find(s.substr(j, i - j)) != st.end()) {
            dp[i] = true;
            break;
          }
        }
      }
      return dp[n];
        }
    }; 
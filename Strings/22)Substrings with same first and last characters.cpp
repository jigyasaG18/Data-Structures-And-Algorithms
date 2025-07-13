Substrings with same first and last characters
Given a string s consisting of lowercase characters, the task is to find the count of all substrings that start and end with the same character.

Examples:
Input: s = "abcab"
Output: 7
Explanation: There are 7 substrings where the first and last characters are the same: "a", "abca", "b", "bcab", "c", "a", and "b"

Input: s = "aba"
Output: 4
Explanation: There are 4 substrings where the first and last characters are the same: "a", "aba", "b", "a"

class Solution {
  public:
    int countSubstring(string &s) {
        // code here
        unordered_map<char,int>mpp;
        int cnt=0;
        for(auto it : s){
            mpp[it]++;
            cnt += mpp[it];
        }
        return cnt;
    }
};
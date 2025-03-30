Longest Palindrome
Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.
Letters are case sensitive, for example, "Aa" is not considered a palindrome.

Example 1:
Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

Example 2:
Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.

class Solution {
    public:
        int longestPalindrome(string s) {
            int n=s.size();
            int oddcnt=0;
            unordered_map<char,int>mpp;
            for(char ch : s){
                mpp[ch]++;
                if(mpp[ch]%2==1) oddcnt++;
                else oddcnt--;
            }
            if(oddcnt>1) return n-oddcnt+1;
            else return n;
        }
    };
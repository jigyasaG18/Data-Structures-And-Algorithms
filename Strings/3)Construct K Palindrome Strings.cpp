Construct K Palindrome Strings
Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.

Example 1:
Input: s = "annabelle", k = 2
Output: true
Explanation: You can construct two palindromes using all characters in s.
Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"

Example 2:
Input: s = "leetcode", k = 3
Output: false
Explanation: It is impossible to construct 3 palindromes using all the characters of s. Here, we have l-1,e-3,t-1,c-1,o-1,d-1. The number of 
distinct singlechar is l-1,e-1,t-1,c-1,o-1,d-1 total is 6 but k is 3 hence, k is smaller which is false.

Example 3:
Input: s = "true", k = 4
Output: true
Explanation: The only possible solution is to put each character in a separate string.

class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length()<k) return false;
        unordered_map<char,int>mpp;
        int singlechar=0; //count of single char in string

        //count freq of each char and put into the map
        for(char c : s){
            mpp[c]++;
        } 

        //count char which are single and in pairs
        for(auto &[ch,freq] : mpp){
            if(freq % 2 == 1){ //its a single character
                singlechar++;
            }
        }
        return (singlechar<=k && k<=s.length()); //k palindrome strings is only possible when you have distinct characters <= k
    }
};
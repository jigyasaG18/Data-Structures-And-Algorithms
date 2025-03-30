Word Pattern
Given a pattern and a string s, find if s follows the same pattern.
Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s. Specifically:
Each letter in pattern maps to exactly one unique word in s.
Each unique word in s maps to exactly one letter in pattern.
No two letters map to the same word, and no two words map to the same letter.
 
Example 1:
Input: pattern = "abba", s = "dog cat cat dog"
Output: true
Explanation: The bijection can be established as:
'a' maps to "dog".
'b' maps to "cat".

Example 2:
Input: pattern = "abba", s = "dog cat cat fish"
Output: false

Example 3:
Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false

class Solution {
    public:
        bool wordPattern(string pattern, string s) {
            unordered_map<char,int>mpp;
            unordered_map<string,int>mpp1;
            istringstream in(s);
            string word;
            int i=0;
            int n=pattern.size();
            for(word;in>>word;i++){
                if(i==n || mpp[pattern[i]]!=mpp1[word]) return false;
                mpp[pattern[i]]=mpp1[word]=i+1;
            }
            return i==n;
        }
    };
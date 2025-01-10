Word Subsets
You are given two string arrays words1 and words2.
A string b is a subset of string a if every letter in b occurs in a including multiplicity.
For example, "wrr" is a subset of "warrior" but is not a subset of "world".
A string a from words1 is universal if for every string b in words2, b is a subset of a.
Return an array of all the universal strings in words1. You may return the answer in any order.

Example 1:
Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
Output: ["facebook","google","leetcode"]

Example 2:
Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["l","e"]
Output: ["apple","google","leetcode"]

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
// Step 1: Build the maximum frequency count for each character needed from words2
        vector<int> maxFrequency(26, 0);
        
        for (const string& word : words2) {
            vector<int> frequency(26, 0);
            for (char c : word) {
                frequency[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                maxFrequency[i] = max(maxFrequency[i], frequency[i]);
            }
        }
        
        vector<string> universalWords;
        
        // Step 2: Check each word in words1 against the maxFrequency 
        for (const string& word : words1) {
            vector<int> frequency(26, 0);
            for (char c : word) {
                frequency[c - 'a']++;
            }
            
            // Check if it meets the requirements
            bool isUniversal = true;
            for (int i = 0; i < 26; i++) {
                if (frequency[i] < maxFrequency[i]) {
                    isUniversal = false;
                    break;
                }
            }
            
            if (isUniversal) {
                universalWords.push_back(word);
            }
        }
        
        return universalWords;
    }
};
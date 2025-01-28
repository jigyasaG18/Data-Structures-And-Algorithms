Permutations of a String
Given a string s, which may contain duplicate characters, your task is to generate and return an array of all unique permutations of the string. You can return your answer in any order.

Examples:
Input: s = "ABC"
Output: ["ABC", "ACB", "BAC", "BCA", "CAB", "CBA"]
Explanation: Given string ABC has 6 unique permutations.

Input: s = "ABSG"
Output: ["ABGS", "ABSG", "AGBS", "AGSB", "ASBG", "ASGB", "BAGS", "BASG", "BGAS", "BGSA", "BSAG", "BSGA", "GABS", "GASB", "GBAS", "GBSA", "GSAB", "GSBA", "SABG", "SAGB", "SBAG", "SBGA", "SGAB", "SGBA"]
Explanation: Given string ABSG has 24 unique permutations.

Input: s = "AAA"
Output: ["AAA"]
Explanation: No other unique permutations can be formed as all the characters are same.

class Solution {
  public:
  // This recursive function generates all permutations of a string
    void function(string temp, unordered_map<char, int> mpp, vector<string>& ans, int n) {
        // Base case: if the length of the temporary string equals the original string size
        if (n == temp.size()) {
            ans.push_back(temp); // Store the generated permutation
            return; // End this recursive branch
        }
        
        // Iterate over each character in the frequency map
        for (auto it : mpp) {
            char c = it.first; // Get the character from the map
            
            // Proceed only if the character is available (count > 0)
            if (it.second > 0) {
                mpp[c]--; // Decrease the count of the character as it's being used
                function(temp + c, mpp, ans, n); // Recurse to create permutations with the new character
                mpp[c]++; // Backtrack: restore the count of the character
            }
        }
    }
    vector<string> findPermutation(string &s) {
        // Code here there
        vector<string> ans; // Vector to store the unique permutations
        unordered_map<char, int> mpp; // Frequency map to count occurrences of each character
        
        // Build the frequency map
        for (auto it : s) {
            mpp[it]++; // Increment the count of the character in the map
        }

        int n = s.length(); // Length of the input string
        string temp = ""; // Initialize an empty temporary string for building permutations
        
        // Start the recursive permutation generation
        function(temp, mpp, ans, n);
        
        return ans; // Return the list of unique permutations
    }
};
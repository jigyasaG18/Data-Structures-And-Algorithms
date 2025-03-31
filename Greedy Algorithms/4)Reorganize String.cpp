Reorganize String
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.
Return any possible rearrangement of s or return "" if not possible.

Example 1:
Input: s = "aab"
Output: "aba"

Example 2:
Input: s = "aaab"
Output: ""

class Solution {
    public:
        string reorganizeString(string s) {
            // Step 1: Count the frequency of each character in the string
            unordered_map<char, int> mpp;
            for (char c : s) {
                mpp[c]++; // Increment the count for each character
            }
    
            // Step 2: Define a comparison function to sort characters by their frequency
            auto comparison = [&mpp](char a, char b) {
                return mpp[a] > mpp[b]; // Return true if character 'a' has a higher frequency than 'b'
            };
    
            // Step 3: Create a vector to hold the characters sorted by frequency
            vector<char> sorted_chars;
            for (auto it : mpp) {
                sorted_chars.push_back(it.first); // Push back each character from the frequency map
            }
    
            // Step 4: Sort the characters in descending order of frequency
            sort(sorted_chars.begin(), sorted_chars.end(), comparison);
    
        // Step 5: Check if the most frequent character exceeds possible placements
            if (mpp[sorted_chars[0]] > (s.length() + 1) / 2) return ""; // If true, return an empty string
    
            // Step 6: Prepare the result string
            string res(s.length(), ' '); // Initialize result with spaces
            int i = 0; // Index to place characters in the result
    
            // Step 7: Fill the result string with characters
            for (char c : sorted_chars) {  // Iterate through each unique character
                for (int j = 0; j < mpp[c]; ++j) { // Repeat for the frequency of that character
                    if (i >= s.length()) { // If we've reached the end of the string,
                        i = 1; // start placing characters at odd indices
                    }
                    res[i] = c; // Place the character at the current index
                    i += 2; // Move to the next available position (even index)
                }
            }
    
            // Step 8: Return the rearranged string
            return res;
        }
    };
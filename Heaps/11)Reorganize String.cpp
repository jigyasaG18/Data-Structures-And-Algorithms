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
            string ans = ""; // Initialize an empty string to hold the result
            unordered_map<char, int> mpp; // Create a hashmap to count the frequency of each character
            priority_queue<pair<int, char>> pq; // Max-heap to store characters by their frequency
    
            // Count the frequency of each character in the input string
            for (auto it : s) 
                mpp[it] ++;
    
            // Push each character and its frequency into the priority queue
            for (auto it : mpp) 
                pq.push(make_pair(it.second, it.first));
    
            // While there are at least two characters left in the priority queue
            while (pq.size() > 1) {
                // Get the most frequent character
                auto top1 = pq.top();
                pq.pop(); // Remove it from the queue
                // Get the second most frequent character
                auto top2 = pq.top();
                pq.pop(); // Remove it from the queue
    
                // Append both characters to the answer string
                ans += top1.second; // Add character from top1
                ans += top2.second; // Add character from top2
    
                // Decrease the frequency of the characters used
                top1.first -= 1;
                top2.first -= 1;
    
                // If there are more occurrences of top1, push it back into the queue
                if (top1.first > 0) 
                    pq.push(top1);
                // If there are more occurrences of top2, push it back into the queue
                if (top2.first > 0) 
                    pq.push(top2);
            }
    
            // Check if there is any character left in the queue
            if (!pq.empty()) {
                // If the frequency of the remaining character is more than 1, it's impossible to reorganize
                if (pq.top().first > 1) 
                    return "";
                else 
                    ans += pq.top().second; // Else, add the remaining character to the result
            }
            return ans; // Return the reorganized string
        }
    };
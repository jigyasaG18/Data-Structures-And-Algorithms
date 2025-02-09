Find the Number of Distinct Colors Among the Balls
You are given an integer limit and a 2D array queries of size n x 2.
There are limit + 1 balls with distinct labels in the range [0, limit]. Initially, all balls are uncolored. For every query in queries that is of the form [x, y], you mark ball x with the color y. After each query, you need to find the number of distinct colors among the balls.
Return an array result of length n, where result[i] denotes the number of distinct colors after ith query.
Note that when answering a query, lack of a color will not be considered as a color.

Example 1:
Input: limit = 4, queries = [[1,4],[2,5],[1,3],[3,4]]
Output: [1,2,2,3]
Explanation:
After query 0, ball 1 has color 4.
After query 1, ball 1 has color 4, and ball 2 has color 5.
After query 2, ball 1 has color 3, and ball 2 has color 5.
After query 3, ball 1 has color 3, ball 2 has color 5, and ball 3 has color 4.

Example 2:
Input: limit = 4, queries = [[0,1],[1,2],[2,2],[3,4],[4,5]]
Output: [1,2,2,3,4]
Explanation:
After query 0, ball 0 has color 1.
After query 1, ball 0 has color 1, and ball 1 has color 2.
After query 2, ball 0 has color 1, and balls 1 and 2 have color 2.
After query 3, ball 0 has color 1, balls 1 and 2 have color 2, and ball 3 has color 4.
After query 4, ball 0 has color 1, balls 1 and 2 have color 2, ball 3 has color 4, and ball 4 has color 5.

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
 // Maps to store the current color of each position and the count of each color
        unordered_map<int, int> ball, color;
        vector<int> ans; // Vector to store the results of each query
        ans.reserve(queries.size()); // Reserve space to avoid reallocations
        int distinct = 0; // Count of distinct colors currently in use

        // Loop through each query
        for(auto &q : queries) {
        int pos = q[0], c = q[1]; // Extract the position and color from the query

            // If there's already a ball at the position (pos)
            if(ball.count(pos)) {
        // Decrease the count of the current color of the ball at that position
                if(--color[ball[pos]] == 0) {
                color.erase(ball[pos]); // Remove color if its count reaches zero
                    distinct--; // Decrease distinct count
                }
            }

            // Update the position with the new color
            ball[pos] = c;
            
            // Increase the count for the new color
         if(++color[c] == 1) 
         distinct++; // If this is the first time this color is used, increase distinct count

            // Store the current distinct count in the answer vector
            ans.push_back(distinct);
        }
        return ans; // Return the results of all queries
    }
}
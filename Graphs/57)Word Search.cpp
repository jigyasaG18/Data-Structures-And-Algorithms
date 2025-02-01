Word Search
You are given a two-dimensional mat[][] of size n*m containing English alphabets and a string word. Check if the word exists on the mat. The word can be constructed by using letters from adjacent cells, either horizontally or vertically. The same cell cannot be used more than once.

Examples :
Input: mat[][] = [['T', 'E', 'E'], ['S', 'G', 'K'], ['T', 'E', 'L']], word = "GEEK"
Output: true
Explanation: The letter cells which are used to construct the "GEEK" are colored.

Input: mat[][] = [['T', 'E', 'U'], ['S', 'G', 'K'], ['T', 'E', 'L']], word = "GEEK"
Output: false
Explanation: It is impossible to construct the string word from the mat using each cell only once.

Input: mat[][] = [['A', 'B', 'A'], ['B', 'A', 'B']], word = "AB"
Output: true
Explanation: There are multiple ways to construct the word "AB".

class Solution {
public:
    bool dfs(int row, int col, int index, vector<vector<int>> &vis, vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        // Check if we have matched all characters in the word
        if (index == word.size()) return true; // Match found

        // Check boundaries and if the current cell is already visited
        if (row < 0 || row >= n || col < 0 || col >= m || vis[row][col] || board[row][col] != word[index]) {
            return false; // Return false if out of bounds, already visited, or does not match the current character
        }

        // Mark the current cell as visited
        vis[row][col] = 1;

        // Define direction vectors for exploring neighbors
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};

        // Explore all four possible directions
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            // Recursive DFS call for the neighbor
            if (dfs(nrow, ncol, index + 1, vis, board, word)) {
                return true; // If found the word, return true.
            }
        }

        // Backtrack: unmark the current cell before returning
        vis[row][col] = 0;
        return false; // Return false if word not found
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Start DFS from each cell
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Only start DFS if the first character matches
                if (board[i][j] == word[0]) {
                    if (dfs(i, j, 0, vis, board, word)) return true; // Found the word
                }
            }
        }
        return false; // Word not found in the board
    }
};
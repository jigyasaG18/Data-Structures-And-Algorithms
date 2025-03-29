Word Search
Given an m x n grid of characters board and a string word, return true if word exists in the grid.
The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example 1:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3:
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false

class Solution {
    public:
    bool func(vector<vector<char>> &board,string word,int row,int col,int ind,int m,int n){
        if(ind == word.size()) return true;
        if(row<0 || col<0 || row==m || col==n || board[row][col]!=word[ind] || board[row][col]=='!') return false;
        char c=board[row][col];
        board[row][col]='!';
        bool t = func(board,word,row-1,col,ind+1,m,n);
        bool r = func(board,word,row,col+1,ind+1,m,n);
        bool b = func(board,word,row+1,col,ind+1,m,n);
        bool l = func(board,word,row,col-1,ind+1,m,n);
        board[row][col]=c;
        return t||r||b||l;
        }
        bool exist(vector<vector<char>>& board, string word) {
            int m=board.size();
            int n=board[0].size();
            int ind=0;
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(board[i][j]==word[ind]){
                        if(func(board,word,i,j,ind,m,n)) return true;
                    }
                }
            }
            return false;
        }
    };
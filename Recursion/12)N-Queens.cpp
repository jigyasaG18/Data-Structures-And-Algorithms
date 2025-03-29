N-Queens
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Example 2:
Input: n = 1
Output: [["Q"]]

1st Way:-
class Solution {
public:
void solve(int col,vector<string>&board,vector<vector<string>>&ans,vector<int>&leftrow,vector<int>&upper_diagonal,vector<int>&lower_diagonal,int &n){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(leftrow[row]==0 && lower_diagonal[row+col]==0 && upper_diagonal[n-1+col-row]==0){
            board[row][col]='Q';
            leftrow[row]=1;
            lower_diagonal[row+col]=1;
            upper_diagonal[n-1+col-row]=1;
            solve(col+1,board,ans,leftrow,upper_diagonal,lower_diagonal,n);
             board[row][col]='.';
            leftrow[row]=0;
            lower_diagonal[row+col]=0;
            upper_diagonal[n-1+col-row]=0;
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n,'.');
        for(int i=0;i<n;i++) board[i]=s;
        vector<int>leftrow(n,0);
        vector<int>upper_diagonal(2*n-1,0);
        vector<int>lower_diagonal(2*n-1,0);
        solve(0,board,ans,leftrow,upper_diagonal,lower_diagonal,n);
        return ans;
    }
};

2nd Way:-

// User function Template for C++

class Solution {
  public:
 void solve(int col, vector<string>& board, vector<vector<int>>& ans, vector<int>& leftrow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal, int n) {
    if (col == n) {
        vector<int> temp;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'Q') {
                    // Store the row index in 1-based format
                    temp.push_back(j + 1);  // Column index + 1
                }
            }
        }
        ans.push_back(temp);
        return;
    }
    for (int row = 0; row < n; row++) {
        if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0) {
            board[row][col] = 'Q';
            leftrow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDiagonal[n - 1 + col - row] = 1;
            solve(col + 1, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
            board[row][col] = '.';
            leftrow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDiagonal[n - 1 + col - row] = 0;
        }
    }
}

    vector<vector<int>> nQueen(int n) {
        // code here
   vector<vector<int>> ans;
    vector<string> board(n, string(n, '.'));
    
    vector<int> leftrow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
    solve(0, board, ans, leftrow, upperDiagonal, lowerDiagonal, n);
    
    return ans;
    }
};

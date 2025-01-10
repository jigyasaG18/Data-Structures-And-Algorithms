Surrounded Regions or Replace O's with X's
You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:
Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

Example 1:
Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Example 2:
Input: board = [["X"]]
Output: [["X"]]

1st Way:-
class Solution {
private:
void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &board, int delrow[], int delcol[]){
    int n=board.size();
    int m=board[0].size();

    vis[row][col]=1;
    for(int i=0;i<4;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];

if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol]=='O'){
    dfs(nrow,ncol,vis,board,delrow,delcol);
}
    }
}
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};

        for(int j=0;j<m;j++){
            //first row
            if(!vis[0][j] && board[0][j]=='O'){
                dfs(0,j,vis,board,delrow,delcol);
            }
            //last row
            if(!vis[n-1][j] && board[n-1][j]=='O'){
                dfs(n-1,j,vis,board,delrow,delcol);
            }
        }

        for(int i=0;i<n;i++){
            //first column
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,vis,board,delrow,delcol);
            }
            //last column
            if(!vis[i][m-1] && board[i][m-1]=='O'){
                dfs(i,m-1,vis,board,delrow,delcol);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};

2nd Way:-
class Solution {
private:
void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> &mat, int delrow[], int delcol[]){
    int n=mat.size();
    int m=mat[0].size();
    vis[row][col]=1;
    
    for(int i=0;i<4;i++){
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];
        
if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && mat[nrow][ncol]=='O'){
    dfs(nrow,ncol,vis,mat,delrow,delcol);
}
    }
}
  public:
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int delrow[]={-1,0,+1,0};
        int delcol[]={0,+1,0,-1};
        
        for(int j=0;j<m;j++){
            //first row
            if(!vis[0][j] && mat[0][j]=='O'){
                dfs(0,j,vis,mat,delrow,delcol);
            }
            //last row
            if(!vis[n-1][j] && mat[n-1][j]=='O'){
                dfs(n-1,j,vis,mat,delrow,delcol);
            }
        }
        
        for(int i=0;i<n;i++){
            //first column
            if(!vis[i][0] && mat[i][0]=='O'){
                dfs(i,0,vis,mat,delrow,delcol);
            }
            //last column
            if(!vis[i][m-1] && mat[i][m-1]=='O'){
                dfs(i,m-1,vis,mat,delrow,delcol);
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && mat[i][j]=='O'){
                    mat[i][j]='X';
                }
            }
        }
        return mat;
    }
};
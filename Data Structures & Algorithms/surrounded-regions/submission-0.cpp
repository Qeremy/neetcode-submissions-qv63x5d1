class Solution {
    
public:
    void dfs(vector<vector<char>>& board, int row, int col){
        if(board[row][col] == '#' || board[row][col] == 'X') return;
        if(board[row][col] == 'O') board[row][col] = '#';
        if(row > 0) dfs(board, row - 1, col);
        if(row < board.size() - 1) dfs(board, row + 1, col);
        if(col > 0) dfs(board, row, col - 1);
        if(col < board[0].size() - 1) dfs(board, row, col + 1);
    }

    void solve(vector<vector<char>>& board) {
        int r = board.size(), c = board[0].size();

        for(int i = 0; i < r; i++){
            if(board[i][0] == 'O') dfs(board, i, 0);
            if(board[i][c - 1] == 'O') dfs(board, i, c - 1);
        }
        for(int j = 0; j < c; j++){
            if(board[0][j] == 'O') dfs(board, 0, j);
            if(board[r - 1][j] == 'O') dfs(board, r - 1, j);
        }

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(board[i][j] == 'O') board[i][j] = 'X';
                if(board[i][j] == '#') board[i][j] = 'O';
            }
        }
    }
};

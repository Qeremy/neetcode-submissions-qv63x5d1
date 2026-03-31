class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {};
        bool col[9][9] = {};
        bool box[9][9] = {};

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.')continue;

                int d = board[i][j] - '1';
                int box_rindex = i/3*3 + d/3;
                int box_cindex = j/3*3 + d%3;
                
                if(row[i][d] || col[j][d] || box[box_rindex][box_cindex]){
                    return false;
                }

                row[i][d] = true;
                col[j][d] = true;
                box[box_rindex][box_cindex] = true;
            }

        }
        return true;
    }
};

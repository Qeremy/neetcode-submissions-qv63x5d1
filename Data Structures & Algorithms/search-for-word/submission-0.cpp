class Solution {
public:
    bool res = false;
    void dfs(vector<vector<char>>& board, string word, int r, int c, int index){
      if(index == word.size()){
         res = true;
         return;
      }
      if(board[r][c] == word[index]){
         if(r > 0){
            dfs(board, word, r-1, c, index+1);
         }
         if(r < board.size() -1){
            dfs(board, word, r+1, c, index+1);
         }
         if(c > 0){
            dfs(board, word, r, c-1, index+1);
         }
         if(c < board[0].size() -1){
            dfs(board, word, r, c+1, index+1);
         }
      }
      
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++){
          for(int j = 0; j < board[0].size(); j++){
            dfs(board, word, i, j, 0);
          }
        }
        return res;
    }
};

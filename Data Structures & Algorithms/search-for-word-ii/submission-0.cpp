class Solution {
private:
    struct TrieNode{
        TrieNode* children[26];
        bool isEnd;
        TrieNode(){
            for(int i = 0; i < 26; i++){
                children[i] = nullptr;
            }
            isEnd = false;
        }
    };

public:
    TrieNode* root;
    vector<string> res;
    string path;
    void dfs(vector<vector<char>>& board, TrieNode* node, int row, int col){
        if(!node) return;
        if(node->isEnd){
            res.push_back(path);
        }

        if(row > 0){
            if(board[row - 1][col] >= 'a'){
                int index = board[row - 1][col] - 'a';
                path += board[row - 1][col];
                board[row - 1][col] -= 'a';
                dfs(board, node->children[index], row - 1, col);
                path.pop_back();    
                board[row - 1][col] += 'a';
            }
        }

        if(row < board.size() - 1){
            if(board[row + 1][col] >= 'a'){
                int index = board[row + 1][col] - 'a';
                path += board[row + 1][col];
                board[row + 1][col] -= 'a';
                dfs(board, node->children[index], row + 1, col);
                path.pop_back();
                board[row + 1][col] += 'a';
            }
        }

        if(col > 0){
            if(board[row][col - 1] >= 'a'){
                int index = board[row][col - 1] - 'a';
                path += board[row][col - 1];
                board[row][col - 1] -= 'a';
                dfs(board, node->children[index], row, col - 1);
                path.pop_back();
                board[row][col - 1] += 'a';
            }
        }

        if(col < board[0].size() - 1){
            if(board[row][col + 1] >= 'a'){
                int index = board[row][col + 1] - 'a';
                path += board[row][col + 1];
                board[row][col + 1] -= 'a';
                dfs(board, node->children[index], row, col + 1);
                path.pop_back();
                board[row][col + 1] += 'a';
            }
        }
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode();

        for(int i = 0; i < words.size(); i++){
            TrieNode* node = root;
            for(int j = 0; j < words[i].size(); j++){
                int index = words[i][j] - 'a';
                if(!node->children[index]) node->children[index] = new TrieNode();
                node = node->children[index];
            }
            node->isEnd = true;
        }

        for(int r  = 0; r < board.size(); r++){
            for(int c = 0; c < board[0].size(); c++){
                int index = board[r][c] - 'a';
                if(root->children[index]){
                    dfs(board, root, r, c);
                }
            }
        }
        return res;
    }
};

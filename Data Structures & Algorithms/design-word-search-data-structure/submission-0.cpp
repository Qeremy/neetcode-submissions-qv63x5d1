class WordDictionary {
private:
    struct DixNode{
        DixNode* children[26];
        bool isEnd;
        DixNode(){
            for(int i = 0; i < 26; i++){
                children[i] = nullptr;
                isEnd = false;
            }
        }
    };
    DixNode* root;

public:
    WordDictionary() {
        root = new DixNode();
    }
    
    void addWord(string word) {
        DixNode* it = root;
        for(int i = 0; i < word.size(); i++){
            it->children[word[i] - 'a'] = new DixNode();
            it = it->children[word[i] - 'a'];
        }
        it->isEnd = true;
    }

    bool found = false;
    void dfs(string word, int start, DixNode* node){
        if (node == nullptr) return;

        if (start == word.size()) {
            if (node->isEnd) found = true;
            return;
        }

        if(word[start] == '.'){
            for(int i = 0; i < 26; i++){
                DixNode* next = node->children[i];
                dfs(word, start + 1, next);
            }
        }
        else{
            DixNode* next = node->children[word[start] - 'a'];
            dfs(word, start + 1, next);
        }
    }

    bool search(string word) {
        DixNode* node = root;
        dfs(word, 0, node);
        return found;
    }
};

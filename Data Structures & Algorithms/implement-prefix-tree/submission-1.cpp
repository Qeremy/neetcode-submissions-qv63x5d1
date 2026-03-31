class PrefixTree {
private:
    struct TrieNode{
        TrieNode* children[26];
        bool isEnd;
        TrieNode() {
            isEnd = false;
            for (int i = 0; i < 26; i++) {
                children[i] = nullptr;
            }
        }
    };
    TrieNode* root;
    

public:

    PrefixTree() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* it = root;
        for(int i = 0; i < word.size(); i++){
            int index = word[i] - 'a';
            if(!it->children[index]) it->children[index] = new TrieNode();
            it = it->children[index];
        }
        it->isEnd = true;
    }
    
    bool search(string word) {
        TrieNode* it = root;
        for(int i = 0; i < word.size(); i++){
            int index = word[i] - 'a';
            if(!it->children[index]){
                return false;
            }
            it = it->children[index];
        }
        if(it->isEnd) return true;
        else{
            return false;
        }
    }
    
    bool startsWith(string prefix) {
        TrieNode* it = root;
        for(int i = 0; i < prefix.size(); i++){
            int index = prefix[i] - 'a';
            if(!it->children[index]){
                return false;
            }
            it = it->children[index];
        }
        return true;
    }
};

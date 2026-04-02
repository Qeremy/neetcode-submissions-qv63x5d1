class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> visited;
        unordered_set<string> dict;
        bool isWord = false;
        for(int i = 0; i < wordList.size(); i++){
            dict.insert(wordList[i]);
            if(wordList[i] == endWord) isWord = true;
        }
        if(!isWord) return 0;

        int layers = 1;

        queue<string> bfs;
        bfs.push(beginWord);

        while(!bfs.empty()){
            layers++;
            string curr = bfs.front();

            // process all items in queue
            int size = bfs.size();
            for(int i = 0; i < size; i++){
                for(int i = 0; i < beginWord.size(); i++){
                    for(int j = 0; j < 26; j++){
                        string tryword = curr;
                        tryword[i] = 'a' + j;
                        if(tryword == endWord) return layers;

                        if(dict.count(tryword) && !visited.count(tryword)){
                            bfs.push(tryword);
                            visited.insert(tryword);
                        }
                    }
                }  
                bfs.pop(); 
            }
        }

        return layers;
    }
};

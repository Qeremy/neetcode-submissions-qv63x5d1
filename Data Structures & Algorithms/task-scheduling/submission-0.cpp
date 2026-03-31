class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<pair<int, char>> maxhp;
        unordered_map<char, int> freq;
        for(char c : tasks){
            freq[c]++;
        }
        for(auto it : freq){
            maxhp.push({it.second, it.first});
        }

        int maxCount = 0;
        int maxFreq = maxhp.top().first;
        while(!maxhp.empty() && maxhp.top().first == maxFreq){
            maxCount++;
            maxhp.pop();
        }

        int maxN = (maxFreq-1) * (n+1) + maxCount;
        int size = tasks.size();
        return max(maxN, size);

    }
};

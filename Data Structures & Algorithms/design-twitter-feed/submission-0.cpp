class Twitter {
public:
    int time;
    unordered_map<int, vector<pair<int, int>>> user; // <userId, pair<time, tweetId>>
    unordered_map<int, unordered_set<int>> following; // <follower, followees>


    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        user[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // time, tweetId
        for(int i = 0; i < user[userId].size(); i++){
            pq.push(user[userId][i]);
            if(pq.size() > 10) pq.pop();
        }
        for(auto &it : following[userId]){
            int n = user[it].size();
            for(int i = 0; i < n; i++){
                pq.push(user[it][i]);
                if(pq.size() > 10) pq.pop();
            }
        }

        priority_queue<pair<int, int>> news;
        while(!pq.empty()){
            news.push(pq.top());
            pq.pop();
        }
        vector<int> newsfeed;
        while(!news.empty()){
            newsfeed.push_back(news.top().second);
            news.pop();
        }
        return newsfeed;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

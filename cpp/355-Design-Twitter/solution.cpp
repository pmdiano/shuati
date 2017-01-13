class Twitter {
    struct Tweet {
        int tweetId;
        int globalId;
        Tweet(): tweetId(0), globalId(0) {}
        Tweet(int tid, int gid): tweetId(tid), globalId(gid) {}
        bool operator<(const Tweet& rhs) const {
            return globalId > rhs.globalId;
        }
    };

    int globalId;
    unordered_map<int, vector<Tweet>> tweets;
    unordered_map<int, unordered_set<int>> follows;
public:
    /** Initialize your data structure here. */
    Twitter() {
        globalId = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(Tweet(tweetId, globalId++));
        follows[userId].insert(userId);
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<Tweet> heap;

        for (int uid : follows[userId]) {
            if (tweets.count(uid)) {
                for (Tweet& t : tweets[uid]) {
                    heap.push(t);
                    if (heap.size() > 10) {
                        heap.pop();
                    }
                }
            }
        }

        while (heap.size()) {
            res.push_back(heap.top().tweetId);
            heap.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        follows[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (follows.count(followerId) && follows[followerId].count(followeeId) &&
            followerId != followeeId) {
            follows[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
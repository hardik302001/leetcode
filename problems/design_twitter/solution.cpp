class Twitter {
public:
    unordered_map<int , unordered_set<int>>following;
    priority_queue<vector<int>>pq;
    int t;
    Twitter() {
        t = 0;   // sorting on basis of time.
    }
    
    void postTweet(int userId, int tweetId) {
        pq.push({t , userId , tweetId});
        t++;
    }
    
    vector<int> getNewsFeed(int userId) {   
        vector<int>ans;
        priority_queue<vector<int>>tmp;    // to keep track of removed posts
        while(pq.size()){
            auto top = pq.top();
            if(top[1]==userId){   // user will see his post
                ans.push_back(top[2]);
            }else if (following[userId].find(top[1])!=following[userId].end()){   // or the posts of person he follows
                ans.push_back(top[2]);
            }
            
            pq.pop();
            tmp.push(top);
            if(ans.size()==10){   // at max 10 posts
                break;
            }
        }
        
        while(tmp.size()){    // add all removed posts back to pq!
            auto top = tmp.top();
            tmp.pop();
            pq.push(top);
        }
        
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

struct tweet {
    int tweetId;
    int time;
    tweet(int tweetId, int time): tweetId(tweetId), time(time) {}
};

struct User {
    int userId;
    vector<tweet> tweets;
    unordered_set<User*> followees;
    User(int userId): userId(userId) {} 
};

struct cpm_less {
    bool operator()(pair<vector<tweet>, int>& a, pair<vector<tweet>, int>& b)const{
        return a.first[a.second].time < b.first[b.second].time;
    }
};

class Twitter {
    int time;
    unordered_map<int, User*> umap;

public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        User *u = getUser(userId);

        u->tweets.push_back(tweet(tweetId, time++));
    }
    
    vector<int> getNewsFeed(int userId) {
        User *u = getUser(userId);
        priority_queue<pair<vector<tweet>, int>, vector<pair<vector<tweet>, int>>, cpm_less> pq;

        auto& followees = u->followees;
        for(auto f: followees) {
            auto& tweets = f->tweets;
            if(!tweets.empty()) {
                pq.push({tweets, tweets.size()-1});
            }
        }

        vector<int> ret;
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            ret.push_back(top.first[top.second].tweetId);
            if(ret.size() == 10) break;
            if(top.second > 0) pq.push({top.first, top.second-1});
        }

        return ret;
    }
    
    void follow(int followerId, int followeeId) {
        User *follower, *followee;
        follower = getUser(followerId);
        followee = getUser(followeeId);

        follower->followees.insert(followee);
    }

    User *getUser(int userId) {
        auto f = umap.find(userId);
        if(f == umap.end()) {
            User *u = new User(userId);
            umap.insert({userId, u});
            return u;
        }

        return f->second;
    }
    
    void unfollow(int followerId, int followeeId) {
        User *follower, *followee;
        follower = getUser(followerId);
        followee = getUser(followeeId);

        auto& followees = follower->followees;
        auto f = followees.find(followee);
        if(f != followees.end()) followees.erase(f);
    }
};

int main() {
    Twitter twitter = Twitter();
twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
twitter.follow(1, 2);    // User 1 follows user 2.
twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.unfollow(1, 2);  // User 1 unfollows user 2.
twitter.getNewsFeed(1);
}
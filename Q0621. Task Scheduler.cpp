#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include <queue>
#include <deque>

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0) return tasks.size();
        int hasher[26];
        memset(hasher, 0, sizeof(hasher));

        for(char t: tasks) hasher[t-'A']++;

        priority_queue<int> pq;
        for(int h: hasher) if(h) pq.push(h);
        
        deque<int> dq = deque<int>(n, 0);
        int capacity = n;
        int idle_dq = 0;
        int ans = 0;
        while(!pq.empty() || idle_dq > 0) {
            if(!pq.empty()) {
                int top = pq.top();
                pq.pop();
                top--;
                
                int front = dq.front();
                if(front) pq.push(front);
                dq.pop_front();
                if(top) idle_dq = n;
                else idle_dq--;
                dq.push_back(top);
            } else {
                idle_dq--;

                int front = dq.front();
                if(front) pq.push(front);
                dq.pop_front();
                dq.push_back(0);
            }
            ans++;
        }

        return ans;
    }
};

int main()
{
    Solution so;
    vector<char> tasks;

    cout << so.leastInterval(tasks = {'A', 'A', 'A', 'B', 'B', 'B'}, 2) << endl;
}
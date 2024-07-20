#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include <unordered_map>
#include <algorithm>
#include "utils/to_string.h"

struct m_ListNode {
    string val;
    m_ListNode *next;
    m_ListNode() : val(0), next(nullptr) {}
    m_ListNode(string x) : val(x), next(nullptr) {}
    m_ListNode(string x, m_ListNode *next) : val(x), next(next) {}
};

class Solution {
    vector<string> ans;

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        sort(tickets.begin(), tickets.end());
        unordered_map<string, pair<m_ListNode *, m_ListNode *>> adj;;
        for(auto t: tickets) {
            auto f = adj.find(t[0]);
            if(f == adj.end()) {
                m_ListNode *head = new m_ListNode("");
                m_ListNode *first = new m_ListNode(t[1]);
                head->next = first;
                adj[t[0]] = {head, first};
            } else {
                f->second.second->next = new m_ListNode(t[1]);
                f->second.second = f->second.second->next;
            }
        }

        ans.clear();
        dfs(adj, "JFK");
        deconstruct(adj);

        vector<string> ans_;
        ans_.push_back("JFK");
        for(int i = ans.size()-1; i >= 0; i--) {
            ans_.push_back(ans[i]);
        }

        return ans_;
    }

    bool dfs(unordered_map<string, pair<m_ListNode *, m_ListNode *>>& adj, string start) {
        if(empty(adj)) {
            return true;
        }

        auto f = adj.find(start);
        m_ListNode *pre = NULL;
        if(f != adj.end()) pre = f->second.first;
        while(pre && pre->next) {
            m_ListNode *cur = pre->next;
            string target = cur->val;
            pre->next = cur->next;
            if(dfs(adj, target)) {
                ans.push_back(target);
                pre->next = cur;
                return true;
            }
            pre->next = cur;
            pre = pre->next;
        }

        return false;
    }

    bool empty(unordered_map<string, pair<m_ListNode *, m_ListNode *>>& umap){
        for(auto p: umap) {
            if(p.second.first && p.second.first->next) return false;
        }

        return true;
    }

    void deconstruct(unordered_map<string, pair<m_ListNode *, m_ListNode *>>& adj) {
        for(auto p: adj) {
            m_ListNode *pre = p.second.first;
            m_ListNode *cur = pre->next;
            while(cur) {
                delete pre;
                pre = cur;
                cur = pre->next;
            }
            delete pre;
        }
    }
};

int main() {
    Solution so;
    vector<vector<string>> tickets = {{"JFK","KUL"}, {"JFK","NRT"}, {"NRT","JFK"}}; 

    cout << to_string(so.findItinerary(tickets)) << endl;
}
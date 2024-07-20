#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include "utils/ListNode.h"
#include <queue>

struct cmp_less
{
    bool operator()(pair<int, ListNode *>& a, pair<int, ListNode *>& b){
        return a.first > b.first;
    }
};


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, cmp_less> pq;
        ListNode *dummy_head = new ListNode();

        for(ListNode *n: lists) {
            if(n) pq.push({n->val, n});
        }

        ListNode *cur_prev = dummy_head;
        while(pq.size()) {
            auto const& top = pq.top();
            ListNode *cur = top.second;
            cur_prev->next = cur;
            cur_prev = cur;
            pq.pop();

            if(cur->next) pq.push({cur->next->val, cur->next});
        }

        ListNode *ret = dummy_head->next;
        delete dummy_head;
        return ret;
    }
};

int main() {
    Solution so;
    vector<ListNode*> lists;

    ListNode list1 = {1,4,5};
    ListNode list2 = {1,3,4};
    ListNode list3 = {2,6};
    cout << so.mergeKLists(lists = {&list1, &list2, &list3})->toString() << endl;
}
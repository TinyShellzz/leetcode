#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include "utils/ListNode.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode *cur = head;
        while(cur) {
            cur = cur->next;
            len++;
        }
        n = len - n;    // NthFromBegin


        if(n == 0) {
            ListNode *res = head->next;
            return res;
        }


        ListNode *pre_n = head;        // previous node of Nth node

        for(int i = 0; i < n - 1; i++) {
            pre_n = pre_n->next;
        }

        ListNode *node_n = pre_n->next;
        pre_n->next = node_n->next;      // delete Nth node

        node_n->next = NULL;
        delete node_n;      // free memory
        return head;
    }
};

int main(){
    Solution so = Solution();
    ListNode list;

    list = {1,2,3,4,5};
    cout << so.removeNthFromEnd(&list, 2)->toString() << endl;
    list = {1};
    cout << so.removeNthFromEnd(&list, 1)->toString() << endl;
    list = {1,2};
    cout << so.removeNthFromEnd(&list, 1)->toString() << endl;
}
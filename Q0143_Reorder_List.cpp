#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <vector>
#include "utils/ListNode.h"

class Solution {
    ListNode *right;
    int deep_limit;
    int len;

public:
    void reorderList(ListNode* head) {
        if(!head->next) return;
        len = 0;
        for(ListNode *cur = head; cur; cur = cur->next) {
            len++;
        }
        deep_limit = len/2;

        solve(head, 1);
    }

    void solve(ListNode *cur, int deep) {
        if(deep == deep_limit) {
            if(len%2 == 1) {
                right = cur->next->next->next;
                ListNode *tmp_4 = cur->next->next;
                cur->next->next = NULL;
                tmp_4->next = cur->next;
                cur->next = tmp_4;
            } else {
                right = cur->next->next;
                ListNode *tmp3 = cur->next;
                tmp3->next = NULL;
            }
            return;
        }

        solve(cur->next, deep+1);
        ListNode *next_right = right->next;
        right->next = cur->next;
        cur->next = right;
        right = next_right;
    }
};

int main() {
    Solution so;
    ListNode list1;

    list1 = {1,2,3,4};
    so.reorderList(&list1);
    cout << list1.toString() << endl;

    list1 = {1,2,3,4,5};
    so.reorderList(&list1);
    cout << list1.toString() << endl;
}
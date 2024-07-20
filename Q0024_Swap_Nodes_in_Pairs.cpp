#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include "utils/ListNode.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *second = head->next;

        ListNode *cur = head;   // cur = 1
        while(cur && cur->next) {
            ListNode *tmp2 = cur->next;         // tmp2 = 2
            ListNode *tmp3 = cur->next->next;  // tmp3 = 3
            if(tmp3) {  // 1->next = 4
                cur->next = tmp3->next == NULL ? tmp3 : tmp3->next;     // with length of ListNode is odd
            } else {
                cur->next = NULL;
            }
            tmp2->next = cur;            // 2->next = 1
            cur = tmp3;            // cur = 3
        }

        return second;
    }
};

int main(){
    Solution so = Solution();
    ListNode list;

    list = {1,2,3,4};
    cout << so.swapPairs(&list)->toString() << endl;
    cout << so.swapPairs(NULL)->toString() << endl;
    list = {1};
    cout << so.swapPairs(&list)->toString() << endl;
    list = {1, 2, 3};
    cout << so.swapPairs(&list)->toString() << endl;

    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include <unordered_set>
#include "utils/ListNode.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow, *fast;
        slow = fast = head;

        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) {  // when two pinter meet
                while(head != slow) {
                    head = head->next;
                    slow = slow->next;
                }
                return head;
            }
        }

        return NULL;
    }
};


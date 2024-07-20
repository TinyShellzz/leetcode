#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode();

        int carry = 0;
        auto cur = head;
        while(l1 && l2) {
            int sum = l1->val + l2->val + carry;
            if(sum > 9) {
                sum = sum - 10;
                carry = 1;
            } else {
                carry = 0;
            }
            cur->next = new ListNode(sum);
            cur = cur->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        if(l1) merge(cur, l1, carry);
        if(l2) merge(cur, l2, carry);
        if(carry != 0) cur->next = new ListNode(carry); 

        return head->next;
    }

    void merge(ListNode *&src, ListNode *l2, int &carry) {
        while(l2) {
            if(carry == 1) {
                int sum = l2->val + carry;
                if(sum < 10) {
                    carry = 0;
                    src->next = new ListNode(sum);
                } else {
                    sum -= 10;
                    carry = 1;
                    src->next = new ListNode(sum);
                }
                src = src->next;
                l2 = l2->next;
            } else {
                src->next = l2;
                break;
            }
        }
    }
};

Solution *s;

int main(){
    s = new Solution();
}
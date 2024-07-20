#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include "utils/ListNode.h"

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *cur = head;

        while(cur && cur->next) {
            ListNode *nx = cur->next;
            int val = gcd(cur->val, nx->val);
            cur->next = new ListNode(val, nx);      // insert

            cur = nx;
        }

        return head;
    }

    // Euclidean Algorithm
    int gcd(int a, int b) {
        while(b) {
            int tmp = b;
            b = a%b;
            a = tmp;
        }
        return a;
    }
};

int main() {
    Solution so;
    ListNode head;

    cout << so.insertGreatestCommonDivisors(&(head = {18,6,10,3}))->toString() << endl;
    cout << so.insertGreatestCommonDivisors(&(head = {7}))->toString() << endl;
    cout << so.insertGreatestCommonDivisors(&(head = {7, 7}))->toString() << endl;
    cout << so.insertGreatestCommonDivisors(&(head = {18,6,10,5,3}))->toString() << endl;

    return 0;
}
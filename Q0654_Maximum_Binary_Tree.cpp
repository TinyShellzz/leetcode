#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include "utils/TreeNode.h"
#include <unordered_map>

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode *dummy_head = new TreeNode(INT32_MAX);

        unordered_map<TreeNode *, TreeNode *> parent;
        TreeNode *cur = dummy_head;
        for(int num: nums) {
            TreeNode *t = new TreeNode(num);
            while(cur->val < t->val) cur = parent[cur];
            t->left = cur->right;
            cur->right = t;
            parent[t] = cur;
            if(t->left) parent[t->left] = t;

            cur = t;
        }

        TreeNode *ret = dummy_head->right;
        delete dummy_head;
        return ret;
    }
};

int main() {
    Solution so;
    vector<int> v;

    cout << so.constructMaximumBinaryTree(v = {3,2,1,6,0,5})->toString() << endl;
    cout << so.constructMaximumBinaryTree(v = {3})->toString() << endl;

    return 0;
}
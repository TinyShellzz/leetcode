#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include "utils/TreeNode.h"

class Solution {
    TreeNode *p, *q;
    TreeNode *ans;

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->p = p;
        this->q = q;
        try {
            solve(root);
        } catch(int const ex) {}

        return ans;
    }

    bool solve(TreeNode *root) {
        if(!root) return 0;

        bool cur = false;
        if(root == p || root == q) cur = true;

        bool left_ret = solve(root->left);
        bool right_ret = solve(root->right);

        if(left_ret || right_ret) {
            if(cur) { ans = root; throw 1;}
            if(left_ret && right_ret) { ans = root; throw 1;}
            return true;
        }
        
        return cur;
    }
};

int main() {
    Solution so;
    TreeNode root;
    TreeNode *p, *q;

    root = {6,2,8,0,4,7,9,-1,-1,3,5};
    p = root.left;
    q = root.left->right;
    cout << so.lowestCommonAncestor(&root, p, q)->val << endl;

    root = {2, 1};
    p = &root;
    q = root.right;
    cout << so.lowestCommonAncestor(&root, p, q)->val << endl;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#include "utils/TreeNode.h"

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;

        if(isSame(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSame(TreeNode *a, TreeNode *b) {
        if(!a || !b) {
            if(!a && !b) return true;
            return false;
        }

        if(a->val != b->val) return false;

        return isSame(a->left, b->left) && isSame(a->right, b->right);
    }
};

int main() {
    Solution so;
    TreeNode root, subRoot;

    root = {3,4,5,1,2};
    subRoot = {4,1,2};
    cout << so.isSubtree(&root, &subRoot) << endl;
}